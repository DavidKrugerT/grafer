#pragma once 
#include "matrix.h"
#include <queue>

class BFS {
	
	size_t currentNodeIndex;

	Queue queue;

	Matrix matrix;

public:


	BFS(Matrix& matrix, size_t startNodeIndex);

	bool execute();

	void getNextNodes();
};