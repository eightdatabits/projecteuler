
#include <stddef.h>
#include <stdint.h>

#include "ProblemFramework.h"

Problem::Problem() :
    m_number( 0 ),
    m_solution( NULL )
{

}

Problem::Problem( const uint32_t Number,
                  const Solution_t Solution ) :
    m_number( Number ),
    m_solution( Solution )
{
}

uint32_t Problem::getNumber() const
{
    return m_number;
}

Problem::Solution_t Problem::getSolution() const
{
    return m_solution;
}

bool Problem::isValid() const
{
    bool isvalid = true;

    if( m_number == 0 ) {
        isvalid = false;
    }

    if( m_solution == NULL ) {
        isvalid = false;
    }

    return isvalid;
}