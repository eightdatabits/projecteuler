
#include <cstdlib>
#include <iostream>
#include <ctime>

#include "SolutionFramework.h"

using namespace std;

int main( int argc, char *argv[] )
{
    for( int32_t i = 0; i < argc; i++ ) {
        uint32_t cur_num = atoi( argv[ i ] );
        Solution cur_soln;

        if( SolutionList::instance().getSolutionByNumber( &cur_soln, cur_num ) == true ) {
            Solution::SolutionFn_t solnFn = cur_soln.getSolution();

            std::clock_t start = std::clock();
            double duration = 0.0;

            solnFn();

            duration = static_cast< double >( std::clock() - start ) / (double)CLOCKS_PER_SEC;

            cout << "####################" << endl;
            cout << "Solution " << cur_num << " time: " << duration << " ms" << endl;
        }
    }

    return 0;
}