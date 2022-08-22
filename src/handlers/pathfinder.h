#pragma once

#include "../config.h"
#include "../extras/headers.h"
#include "../extras/typedefs.h"


namespace handlers
{
	class Pathfinder
	{
	public:
		Pathfinder();

		type::Vec_Position FindPath(type::Position posStart, type::Vec_Position posDestinations, type::Vec_Position posCollisions);

	private:
		struct Node
		{
			type::Position position;

			float distanceToStart = INFINITY;
			float distanceToEnd = INFINITY;

			bool isObstacle = false;
			bool isVisited = false;

			std::shared_ptr<Node> parent = nullptr;
			std::vector<std::shared_ptr<Node>> neighbours;

			Node(int x, int y) : position({ x, y }) {}
		};

		std::vector<std::shared_ptr<Node>> nodes;

	};
}