
#include <iostream>

#include "SolutionFramework.h"

using namespace std;

/**
 * @brief Problem 1
 *
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
 * The sum of these multiples is 23.
 *
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */
void problem_1_solution( void )
{
    const uint32_t STOP_NUM = 1000;
    uint32_t sum = 0;

    // Start with the i=1 multiple
    uint32_t three_multiple = 3;
    for( uint32_t i = 2; three_multiple < STOP_NUM; i++ ) {
        // Count all three multiples (even if they are also five multiples)
        sum += three_multiple;
        three_multiple = 3 * i;
    }

    // Start with the i=1 multiple
    uint32_t five_multiple = 5;
    uint32_t three_counter = 1;
    for( uint32_t i = 2; five_multiple < STOP_NUM; i++ ) {
        // Don't double count a three multiple
        if( three_counter == 3 ) {
            three_counter = 0;
        } else {
            sum += five_multiple;
        }

        five_multiple = 5 * i;
        three_counter++;
    }

    cout << "Sum: " << sum << endl;
}

ADD_SOLUTION( 1, problem_1_solution );