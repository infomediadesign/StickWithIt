#include "pathfinder.h"

handlers::Pathfinder::Pathfinder()
{
	// Fill up vector with nodes
	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			nodes.push_back(std::make_shared<Node>(x, y));
		}
	}


	// Set neighbours of each node
	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			if (nodes[y * 20 + x]->position.second > 0)
				nodes[y * 20 + x]->neighbours.push_back(nodes[y * 20 + x - 20]);

			if (nodes[y * 20 + x]->position.second < 12 - 1)
				nodes[y * 20 + x]->neighbours.push_back(nodes[y * 20 + x + 20]);

			if (nodes[y * 20 + x]->position.first > 0)
				nodes[y * 20 + x]->neighbours.push_back(nodes[y * 20 + x - 1]);

			if (nodes[y * 20 + x]->position.first < 20 - 1)
				nodes[y * 20 + x]->neighbours.push_back(nodes[y * 20 + x + 1]);
		}
	}
}


// Finds the shortest path to the closest destination WITHOUT consideration of collisions
// If it should find the smartest destination then we would have to compare the length of all paths.
type::Vec_Position handlers::Pathfinder::FindPath(type::Position posStart, type::Vec_Position posDestinations, type::Vec_Position posCollisions)
{
	// Evaluate distance between two points
	auto GetDistance = [](type::Position point1, type::Position point2)
	{
		return sqrtf((point1.first - point2.first) * (point1.first - point2.first) + (point1.second - point2.second) * (point1.second - point2.second));
	};


	// Reset all node properties
	for (auto& node : nodes)
	{
		node->distanceToEnd = INFINITY;
		node->distanceToStart = INFINITY;
		node->isObstacle = false;
		node->isVisited = false;
		node->parent = nullptr;
	}


	// Set all nodes of posCollision to isObstacle = true
	// This includes position of nodeStart and nodeEnd
	for (auto& collision : posCollisions)
	{
		nodes[collision.second * 20 + collision.first]->isObstacle = true;
	}


	// Init nodeStart and nodeEnd
	std::shared_ptr<Node> nodeStart = nodes[posStart.second * 20 + posStart.first];
	std::shared_ptr<Node> nodeEnd = nullptr;


	// Set nodeEnd
	float finalDestination = INFINITY;
	for (auto& posDestination : posDestinations)
	{
		if (GetDistance(posStart, posDestination) < finalDestination)
		{
			finalDestination = GetDistance(posStart, posDestination);
			nodeEnd = nodes[posDestination.second * 20 + posDestination.first];
		}
	}


	// Tell pathfinder, that nodeStart and nodeEnd are walkable
	nodeStart->isObstacle = false;
	nodeEnd->isObstacle = false;


	// Set properties of nodeStart
	nodeStart->distanceToStart = 0;
	nodeStart->distanceToEnd = GetDistance(nodeStart->position, nodeEnd->position);


	// Init current node that will be used to find path
	std::shared_ptr<Node> nodeCurrent = nullptr;


	// Init list that will hold every node that is in reach but has not been visited yet
	std::list<std::shared_ptr<Node>> openList;
	openList.push_back(nodeStart);


	// Start actual pathfinding here
	while (openList.empty() == false && nodeStart != nodeEnd)
	{
		// Sort openList by distanceToEnd
		openList.sort([](std::shared_ptr<Node> node1, std::shared_ptr<Node> node2) {return node1->distanceToEnd < node2->distanceToEnd; });


		// Pop front of list as long as the first element has not been visited
		while (openList.empty() == false && openList.front()->isVisited == true)
			openList.pop_front();


		// Break loop when openList is empty (happens when theres no path to the destination)
		if (openList.empty() == true)
		{
			std::cout << "There is no path to the destination" << std::endl;
			break;
		}


		// The current node will be the front element of our openList, hence has not been visited yet and has the smallest distanceToEnd
		nodeCurrent = openList.front();
		nodeCurrent->isVisited = true;


		// Add neighbours of currentNode to the openList, also change parent if the path would shorten
		for (auto& neighbour : nodeCurrent->neighbours)
		{
			// Push legit neighbour into openList
			if (neighbour->isObstacle == false && neighbour->isVisited == false)
				openList.push_back(neighbour);


			// Evaluate neighbours properties
			float possiblyLowerDistanceToStart = nodeCurrent->distanceToStart + 1;
			if (neighbour->isObstacle == false)
			{
				if (possiblyLowerDistanceToStart < neighbour->distanceToStart)
				{
					neighbour->parent = nodeCurrent;
					neighbour->distanceToStart = nodeCurrent->distanceToStart + 1;
				}
				neighbour->distanceToEnd = GetDistance(neighbour->position, nodeEnd->position);
			}
		}


		// Build the path once the end has been reached
		type::Vec_Position path;
		if (nodeCurrent == nodeEnd)
		{
			while (nodeCurrent->parent != nullptr)
			{
				path.push_back(nodeCurrent->position);
				nodeCurrent = nodeCurrent->parent;
			}

			return path;
		}
	}


	return { {nodeStart->position} };
}
