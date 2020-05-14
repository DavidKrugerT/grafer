#include "dfs.h"
#include <algorithm>

DFS::DFS(Matrix & matrix, size_t startNodeIndex)
	: currentNodeIndex(startNodeIndex), matrix(matrix) {
	stack.push(currentNodeIndex);
}

bool DFS::execute()
{
	
	while(stack.size() > 0) {
		currentNodeIndex = stack.top();
		getNextNode();
	}
	return true;
}

void DFS::getNextNode()
{
	/** Hitta en nod som inte är visited*/
	auto iterator = std::find_if(matrix.begin(), matrix.end(), [&](std::vector<Edge*>& row) {
		Edge* edge = row[currentNodeIndex];
		if(edge != nullptr) {
			/** Ta rätt nod, inte sig själv*/
			Node* node = edge->n1->id != currentNodeIndex ? edge->n1 : edge->n2;
			if(!node->visited) {
				node->visited = true;
				return true;
			}
		}
		return false;
	});

	/** Hittat en nod som inte är visited */
	if(iterator != matrix.end()) {
		stack.push(iterator - matrix.begin());
		
	}
	/* Inte hittat en nod*/
	else {
		stack.pop();
	}
}



