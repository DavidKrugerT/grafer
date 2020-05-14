#include "matrix.h"

#include <vector>


Edge * Matrix::readEdge(std::istream& is)
{
    Edge* e = new Edge();
    int id1, id2;

    is >> id1 >> id2 >> e->weight;

    //vi hämtar n1 referense och lägger in id1 samma för id2 där de lagras och vi
    //kan senare peka på dessa.
    e->n1 = nodes[id1];
    e->n2 = nodes[id2];

    std::getline(is, e->description);
    return e;
}

Matrix::Matrix()
{

} 

token Matrix::getLineType(std::ifstream& is)
{
    switch (static_cast<char>(is.peek()))
    {
    case std::istream::traits_type::eof():  return END_OF_FILE;
    case '#':                               return COMMENT;
    case 'M':                               return NODE;
    };
    return EDGE;
}

Node * Matrix::readNode(std::istream& is)
{
    Node * n = new Node();
    is.ignore();
    is >> n->id;
    is.ignore();
    std::getline(is, n->name);
    return n;
}

void Matrix::parseFile(std::string& filename)
{
    std::ifstream in(filename);
    if (in.is_open())
    {  
        token t;
        Edge* e;
        Node* n;
        while ((t = getLineType(in)) != token::END_OF_FILE)
        {
            std::string trash;
            switch (t)
            {
            case token::COMMENT:
                std::getline(in, trash);
                break;
            case token::EDGE:
                e = readEdge(in);
                this->edges.push_back(e);
                break;
            case token::NODE:
                n = readNode(in);
                this->nodes.push_back(n);
                break;
            default:
                break;
            };
        };
    }
    else
    {
        std::cout << "ERROR::MATRIX::PARSEFILE" << std::endl;
    }
}

void Matrix::printNodes()const
{
    for (size_t i = 0; i < nodes.size(); i++)
    {
        std::cout << nodes[i]->id << " " << nodes[i]->name << " visited:" << nodes[i]->visited << "\n";
    }
}

void Matrix::printEdges() const
{
    for (size_t i = 0; i < edges.size(); i++)
    {
        std::cout << edges[i]->n1->id << " " << edges[i]->n2->id << " " <<
            edges[i]->weight << " " << edges[i]->description << std::endl;
    }
}
// fråga herman
void Matrix::fillMatrix()
{
    for(int i = 0; i < nodes.size(); i++) {
       this->push_back(std::vector<Edge*>(nodes.size()));
	}

    for (auto e : edges) {
        /*std::cout << e->n1->id << '\t' << e->n2->id << '\t' << e->weight <<std::endl;*/
        this->operator[](e->n1->id)[e->n2->id] = e;
	}
}

void Matrix::displayMatrix() const {

    for(auto row : *this) {
        for(auto edgePtr : row) {

            if(edgePtr != nullptr) {
                std::cout <<static_cast<int>(edgePtr->weight) << (edgePtr->weight >= 10 ? " " : "  ");
			}
            else {
                std::cout << "0  ";
			}
		}
        std::cout << std::endl;
	}
}







