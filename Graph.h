#ifndef GRAPH
#define GRAPH

#include <fstream>
#include <iostream>
#include <vector>

namespace aisdi
{
struct Vertice
{
    int vertCount;
    int number;
    int *edgeTable;
    Vertice():vertCount(0),number(0), edgeTable(nullptr)
    {}
    Vertice(int deg, int nmber):vertCount(deg), number(nmber)
    {
        edgeTable = new int[deg];
        for(int i=0;i<deg;++i)edgeTable[i]=0;
    }
    int &operator[](int numb);
    bool areTableEq(Vertice &other);
    void swap(Vertice *other);
};

class Graph
{
    public:
    int verticeCount;
    std::vector<Vertice*> verticeVector;
    Graph():verticeCount(0)
    {}
    Graph(std::string fileGraph);
    bool operator==(Graph &other) const;
    int findVertice(int number);
    bool isIsomorph(Graph &other);
    void Permute(int *permuteTable);
};
}
#endif
