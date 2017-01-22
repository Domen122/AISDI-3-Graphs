#include "Graph.h"
#include <algorithm>
#include <utility>
using namespace aisdi;

int& Vertice::operator[](int numb)
{
    return edgeTable[numb];
}
bool Vertice::areTableEq(Vertice &other)
{
    for(int i=0; i<vertCount;++i)
    {
        if(edgeTable[i]!=other.edgeTable[i]) return false;
    }
    return true;
}
void Vertice::swap(Vertice *other)
{
    std::swap(number, other->number);
    std::swap(edgeTable, other->edgeTable);

}

Graph::Graph(std::string fileGraph)
{
    std::fstream file;
    file.open(fileGraph, std::ios::in);
    if(file.good()){
    file >> verticeCount;
    for(int i=0;i<verticeCount;++i)
    {
        Vertice *A=new Vertice(verticeCount, i);
        verticeVector.push_back(A);
    }
    while(file.good())
    {
        int vertA, vertB;
        file >> vertA >> vertB;
        verticeVector[vertA]->operator[](vertB)=1;
        verticeVector[vertB]->operator[](vertA)=1;
    }
    }
    file.close();
}
bool Graph::operator==(Graph &other) const
{
    if(verticeCount!=other.verticeCount)return false;
    for(int i=0;i<verticeCount;++i)
    {
        //if(verticeVector[i]!=other.verticeVector[i])return false;
        if(!(verticeVector[i]->areTableEq(*other.verticeVector[i])))return false;
    }
    return true;
}

int Graph::findVertice(int numb)
{
    for(int i=0; i<verticeCount;++i)
    {
        if(verticeVector[i]->number==numb)return i;
    }
}

bool Graph::isIsomorph(Graph &other)
{
    if(verticeCount!=other.verticeCount)return false;
    if((*this)==other)
    {
        std::cout<<"Izomorficzne"<<std::endl;
        for(int i=0;i<verticeCount;++i)std::cout<<i<<" --> "<<i<<std::endl;
        return true;
    }
    int *next_perm= new int[verticeCount];
    for(int i=0;i<verticeCount;++i)next_perm[i]=i;
    while(std::next_permutation(next_perm,next_perm+verticeCount))
    {
        Permute(next_perm);
        if((*this)==(other))
        {
            std::cout<<"Izomorficzne"<<std::endl;
            for(int i=0;i<verticeCount;++i)std::cout<<i<<" --> "<<next_perm[i]<<std::endl;
            return true;
        }
    }
    return false;
}

void Graph::Permute(int *permuteTable)
{
    for(int i=0;i<verticeCount-1;++i)
    {
        if(permuteTable[i]!=verticeVector[i]->number)
        {
            int foundVert = findVertice(permuteTable[i]);
            verticeVector[foundVert]->swap(verticeVector[i]);
            for(int j=0; j<verticeCount;++j)
            {
                int temp = verticeVector[j]->operator[](i);
                verticeVector[j]->operator[](i)=verticeVector[j]->operator[](foundVert);
                verticeVector[j]->operator[](foundVert)=temp;
            }
        }
    }
}

