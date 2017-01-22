#include <iostream>
#include "Graph.h"

using namespace aisdi;

int main(int argc, char * argv[] )
{
    std::cout<<argv[1]<<std::endl;
    Graph A(argv[1]);
    std::cout<<argv[2]<<std::endl;
    Graph B(argv[2]);
    void(A.isIsomorph(B));
    return 0;
}
