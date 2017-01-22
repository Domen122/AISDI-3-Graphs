#include <iostream>
#include "Graph.h"

using namespace aisdi;

int main(int argc, char * argv[] )
{
    std::cout<<argv[1]<<std::endl;
    Graph A(argv[1]);
    std::cout<<argv[2]<<std::endl;
    Graph B(argv[2]);
     if(A.isIsomorph(B));
    /*for(int i=0;i<B.verticeCount;++i)
    {
        for(int j=0;j<B.verticeCount;++j)
        {
            std::cout<<B.verticeVector[j]->operator[](i)<<" ";
        }
        std::cout<<std::endl;
                std::cout<<std::endl;

    }
    for(int i=0;i<A.verticeCount;++i)
    {
        for(int j=0;j<A.verticeCount;++j)
        {
            std::cout<<A.verticeVector[j]->operator[](i)<<" ";
        }
        std::cout<<std::endl;
                std::cout<<std::endl;

    }*/
    return 0;
}
