
#include <cstdlib>
#include <iostream>
#include <ctime>

#include "ProblemFramework.h"

using namespace std;

int main( int argc, char *argv[] )
{
    for( int32_t i = 0; i < argc; i++ ) {
        uint32_t cur_num = atoi( argv[ i ] );
        Problem cur_prob;

        if( ProblemList::instance().getProblemByNumber( &cur_prob, cur_num ) == true ) {
            Problem::Solution_t soln = cur_prob.getSolution();

            std::clock_t start = std::clock();
            double duration = 0.0;

            soln();

            duration = static_cast< double >( std::clock() - start ) / (double)CLOCKS_PER_SEC;

            cout << "####################" << endl;
            cout << "Problem " << cur_num << " time: " << duration << " ms" << endl;
        }
    }

    return 0;
}