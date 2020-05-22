// Laboration 1 Datastruktor
// Author David Tropa Krüger
// https://www.tutorialspoint.com/cplusplus-program-to-implement-adjacency-matrix

#include "matrix.h"
#include "dfs.h"
#include "BFS.h"
#include <iostream>
#include <string>

int main() 
{
	std::string filename = "export.txt";
	Matrix m;
	m.parseFile(filename);
	m.fillMatrix();
	m.displayMatrix();

	/** DFS kollar ifall noderna är sammanhängande */
	BFS dfs(m, 0);
	dfs.execute();
	m.printNodes();
}
