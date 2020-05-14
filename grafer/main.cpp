// Laboration 1 Datastruktor
// Author David Tropa Kr�ger
// https://www.tutorialspoint.com/cplusplus-program-to-implement-adjacency-matrix

#include "matrix.h"
#include "dfs.h"
#include <iostream>
#include <string>

int main() 
{
	std::string filename = "export.txt";
	Matrix m;
	m.parseFile(filename);
	m.fillMatrix();
	m.displayMatrix();

	/** DFS kollar ifall noderna �r sammanh�ngande */
	//DFS dfs(m, 0);
	//dfs.execute();
	//m.printNodes();
}
