
#include <stddef.h>
#include <stdint.h>

#include <list>

#include "SolutionFramework.h"

using namespace std;

SolutionList & SolutionList::instance()
{
    static SolutionList solution_list;

    return solution_list;
}

SolutionList::SolutionList() :
    m_SolutionList()
{
}

bool SolutionList::addSolution( const Solution &Soln )
{
    bool success = false;

    if( Soln.isValid() == true ) {
        m_SolutionList.push_back( Soln );
        success = true;
    }

    return success;
}

bool SolutionList::getSolutionByNumber( Solution * const pSoln, const uint32_t Number ) const
{
    bool success = false;

    if( (pSoln != NULL)             &&
        (m_SolutionList.size() > 0) )
    {
        // Iterate over list
        for( list< Solution >::const_iterator iter = m_SolutionList.begin(); iter != m_SolutionList.end(); iter++ ) {
            // Find Solution in list with matching number
            if( iter->getNumber() == Number ) {
                *pSoln = *iter;
                success = true;
                break;
            }
        }
    }

    return success;
}
