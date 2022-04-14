
#include <stddef.h>
#include <stdint.h>
#include <iostream>

#include "SolutionFramework.h"

Solution::Solution() :
    m_number( 0 ),
    m_solutionFn( NULL )
{

}

Solution::Solution( const uint32_t Number,
                  const SolutionFn_t Solution ) :
    m_number( Number ),
    m_solutionFn( Solution )
{
}

uint32_t Solution::getNumber() const
{
    return m_number;
}

bool Solution::run() const
{
    if (!isValid())
    {
        return false;
    }

    std::clock_t start = std::clock();
    double duration = 0.0;

    m_solutionFn();

    duration = static_cast< double >( std::clock() - start ) / (double)CLOCKS_PER_SEC;

    std::cout << "Solution " << m_number << " time: " << duration << " ms" << std::endl;
    std::cout << "####################" << std::endl;
    return true;
}

bool Solution::isValid() const
{
    bool isvalid = true;

    if( m_number == 0 ) {
        isvalid = false;
    }

    if( m_solutionFn == NULL ) {
        isvalid = false;
    }

    return isvalid;
}