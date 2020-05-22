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
		currentNodeIndex = queue.pop();
		getNextNodes();
	}
	return true;
}

void BFS::getNextNodes()
{
	std::for_each(matrix.begin(), matrix.end(), [&](std::vector<Edge*> row) {
		Edge* edge = row[currentNodeIndex];
		if (edge != nullptr)
		{
			Node* node = edge->n1->id != currentNodeIndex ? edge->n1 : edge->n2;
			if (!node->visited)
			{
				node->visited = true;
				queue.push(node->id);
				return true;
			}
		}
		return false;
	});
}
