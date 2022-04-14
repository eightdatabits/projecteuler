
#include <cstdlib>
#include <iostream>
#include <ctime>

#include "SolutionFramework.h"

using namespace std;

int main( int argc, char *argv[] )
{
    if (argc == 1) {
        for (int i = 0; i < 1000; i++) {
            Solution solution;
            if (SolutionList::instance().getSolutionByNumber(&solution, i) == true) {
                solution.run();
            }
        }
    } else {
        for( int32_t i = 0; i < argc; i++ ) {
            uint32_t cur_num = atoi( argv[ i ] );
            Solution solution;

            if( SolutionList::instance().getSolutionByNumber( &solution, cur_num ) == true ) {
                solution.run();
            }
        }
    }

    return 0;
}