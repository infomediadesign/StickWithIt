#include <iostream>
#include <vector>
#include <memory>
#include <math.h>
#include <list>

//https://github.com/OneLoneCoder/videos/blob/master/OneLoneCoder_PathFinding_AStar.cpp

// Eine Funktion, die das Grid nach dem Laufen jedes Gegners updatet.
// Position des Objekts, ist (y/32) * mapWidth + (x/32)
// End node = closest distance() from start node to player objects / ritual tiles

using namespace std;

// One node resembles one unique tile
struct sNode
{
	bool isObstacle = false;		// Every object on map + collision layer would resemble an object-node
	bool isVisited = false;			// Checks if node has already been checked or not
	float globalGoal = 0;			// The distance from node to start node + distance from node to end node
	float localGoal = 0;			// The distance from node to start node
	int x = 0;						// Position x
	int y = 0;						// Position y
	vector<sNode*> vecNeighbours;	// Vector with all neighbouring nodes
	sNode* parent = nullptr;		// Parent node
};

// Allocate memory for node-vector that has size of width and height of the game (in tiles)
sNode* nodes = nullptr;
const int mapWidth = 4;
const int mapHeight = 4;

// Allocate memory for start and end node
sNode* nodeStart = nullptr;
sNode* nodeEnd = nullptr;

bool OnUserCreate()
{
	// Initialize a vector of nodes
	nodes = new sNode[mapWidth * mapHeight];

	// Fill vector with nodes and set their position depending of position in vector
	for (int x = 0; x < mapWidth; x++)
	{
		for (int y = 0; y < mapHeight; y++)
		{
			nodes[y * mapWidth + x].x = x;
			nodes[y * mapWidth + x].y = y;
		}
	}

	// Put neighbours of node in its vecNeighbour (by reference!)
	for (int x = 0; x < mapWidth; x++)
	{
		for (int y = 0; y < mapHeight; y++)
		{
			if (y > 0)
				nodes[y * mapWidth + x].vecNeighbours.push_back(&nodes[(y - 1) * mapWidth + (x + 0)]);

			if (y < mapHeight - 1)
				nodes[y * mapWidth + x].vecNeighbours.push_back(&nodes[(y + 1) * mapWidth + (x + 0)]);

			if (x > 0)
				nodes[y * mapWidth + x].vecNeighbours.push_back(&nodes[(y - 0) * mapWidth + (x - 1)]);

			if (x < mapWidth - 1)
				nodes[y * mapWidth + x].vecNeighbours.push_back(&nodes[(y - 0) * mapWidth + (x + 1)]);
		}
	}

	// Create obstacles manually, later this should become automized and nodes would be changed depending on collision layer
	nodes[1].isObstacle = true;
	nodes[5].isObstacle = true;
	nodes[9].isObstacle = true;
	nodes[10].isObstacle = true;

	// Assign nodes of vector to start node and end node, later this should become automized
	// We need to get the closest end node first (player-object or ritual tile)
	nodeStart = &nodes[0];
	nodeEnd = &nodes[3];

	return true;
}

bool FindPath()
{
	// Before a node hasn't been tested yet its distance to other nodes is infinite
	for (int x = 0; x < mapWidth; x++)
	{
		for (int y = 0; y < mapHeight; y++)
		{
			nodes[y * mapWidth + x].globalGoal = INFINITY;
			nodes[y * mapWidth + x].localGoal = INFINITY;
		}
	}

	// Lambda function to calculate the distance from node 'a' to node 'b' using Pythagoras
	auto distance = [](sNode* a, sNode* b)
	{
		return sqrtf((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y)); //funfact: return 1 -> daijkstra 
	};

	// Set start node as current node, it's local goal is 0 (distance to start node)
	// It's global goal is distance to itself (0) + distance to end node
	nodeStart->localGoal = 0.0f;
	nodeStart->globalGoal = distance(nodeStart, nodeEnd);

	// Create a list that contains all un-visited nodes that are in reach of visited nodes
	// Add start node to the list
	list<sNode*> openList;
	openList.push_back(nodeStart);

	// The current node will hold the node to be evaluated at the moment
	sNode* nodeCurrent = nullptr;

	// As long as the list is not empty and the destination hasn't been found
	while (!openList.empty() && nodeCurrent != nodeEnd)
	{
		// Labda function to sort the open list by the nodes global goal
		openList.sort([](const sNode* node1, const sNode* node2) { return node1->globalGoal < node2->globalGoal; });

		// As long as the list is not empty: remove all visited nodes with the lowest global goal from the list
		while (!openList.empty() && openList.front()->isVisited)
			openList.pop_front();

		// If the list is now empty, break
		if (openList.empty())
			break;

		// Set first node of list as current node and mark as visited
		nodeCurrent = openList.front();
		nodeCurrent->isVisited = true;

		// For each neigbour of current node:
		for (auto nodeNeighbour : nodeCurrent->vecNeighbours)
		{
			// If it has not been visited yet and if it isn't an obstacle add it to the list
			if (!nodeNeighbour->isVisited && !nodeNeighbour->isObstacle)
			{
				openList.push_back(nodeNeighbour);
			}

			// Evualuate a possibly lower local goal for neighbour
			// It's the sum of current nodes local goal + distance from current node to neighbour (always 1 because no diagonal movement allowed)
			float possiblyLowerGoal = nodeCurrent->localGoal + distance(nodeCurrent, nodeNeighbour);

			// If the possibly lower goal is lesser than neighbours local goal:
			// Set neighbours parent to current node (to ensure we get the fastest path to neighbour)
			// Set local goal of neighbour to possibly lower goal
			// Set global goal of neigbour to the sum of distance to start + distance to end (f cost)
			// https://youtu.be/-L-WgKMFuhE?t=293
			if (possiblyLowerGoal < nodeNeighbour->localGoal)
			{
				nodeNeighbour->parent = nodeCurrent;
				nodeNeighbour->localGoal = possiblyLowerGoal;
				nodeNeighbour->globalGoal = nodeNeighbour->localGoal + distance(nodeNeighbour, nodeEnd); // F-cost
			}
		}

		// If the current node is the end node: cout path
		if (nodeCurrent == nodeEnd)
		{
			while (nodeCurrent != nullptr)
			{
				cout << nodeCurrent->x << " " << nodeCurrent->y << endl;
				nodeCurrent = nodeCurrent->parent;
			}

			break;
		}
	}

	return true;
}

int main() {
	OnUserCreate();
	FindPath();
}