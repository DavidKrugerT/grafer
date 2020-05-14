#include "BFS.h"
#include <algorithm>

BFS::BFS(Matrix& matrix, size_t startNodeIndex) : currentNodeIndex(startNodeIndex), matrix(matrix)
{
	queue.push(currentNodeIndex);
}

bool BFS::execute()
{
	while (queue.size() > 0)
	{
		
	}
	return true;
}

void BFS::getNextNodes()
{
	auto iterator = std::find_if(matrix.begin(), matrix.end(), [&](std::vector<Edge*>& row)
	{
		Edge* edge = row[currentNodeIndex];
		if (true)
		{
			if (edge != nullptr)
			{
				Node* node = edge->n1->id != currentNodeIndex ? edge->n1 : edge->n2;
				if (!node->visited)
				{
					node->visited = true;
					return true;
				}
			}
		}
	});

	if (iterator != matrix.end())
	{
		queue.push(iterator - matrix.begin());
	}
}
