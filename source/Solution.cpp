
#include <stddef.h>
#include <stdint.h>

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

Solution::SolutionFn_t Solution::getSolution() const
{
    return m_solutionFn;
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