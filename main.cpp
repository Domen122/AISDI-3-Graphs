#include <iostream>
#include "Graph.h"

using namespace aisdi;

Graph graphFromFile(std::string fileGraph)
{
    std::fstream file;
    Graph B;
    file.open(fileGraph, std::ios::in);
    if(file.good())
    {
    file >> B.verticeCount;
    for(int i=0;i<B.verticeCount;++i)
    {
        Vertice *A=new Vertice(B.verticeCount, i);
        B.verticeVector.push_back(A);
    }
    while(file.good())
    {
        int vertA, vertB;
        file >> vertA >> vertB;
        B.verticeVector[vertA]->operator[](vertB)=1;
        B.verticeVector[vertB]->operator[](vertA)=1;
    }
    }
    file.close();
    return B;
}

void checkEQ(Graph A, Graph B)
{
    std::pair<bool, int*> CheckIs=A.isIsomorph(B);
    if(CheckIs.first==true)
    {
        std::cout<<"Izomorficzne"<<std::endl;
        for(int i=0;i<A.verticeCount;++i)std::cout<<i<<" --> "<<CheckIs.second[i]<<std::endl;
    }
    else std::cout<<"Nieizomorficzne"<<std::endl;
}
int main(int argc, char *argv[] )
{
    Graph A(graphFromFile(argv[1]));
    Graph B(graphFromFile(argv[2]));
    checkEQ(A,B);
    return 0;
}
