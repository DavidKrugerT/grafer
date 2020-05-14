#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <istream>
#include <fstream>
#include <algorithm>

enum token
{
	COMMENT, NODE, EDGE, END_OF_FILE
};

struct Node
{
	int id;
	bool visited = false;
	std::string name;
};

struct Edge
{
	Node *n1, *n2;
	double weight;
	std::string description;
};


class Matrix : public std::vector<std::vector<Edge*>>
{
	//vectors for nodes, edges and 2D vector for matrix
	std::vector<Node*> nodes;
	std::vector<Edge*> edges;


	//private functions
	Edge *readEdge(std::istream& is);

public:
	Matrix();
	token getLineType(std::ifstream& is);
	Node *readNode(std::istream& is);
	void parseFile(std::string& filename);
	void printNodes()const;
	void printEdges()const;
	void fillMatrix();
	void displayMatrix()const;
};
