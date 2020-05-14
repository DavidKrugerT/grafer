#pragma once
#include "matrix.h"
#include <stack>


class DFS {

	size_t currentNodeIndex;

	std::stack<size_t> stack;

	Matrix matrix;

public:

	DFS(Matrix & matrix, size_t startNodeIndex);

	bool execute();

	void getNextNode();

};
