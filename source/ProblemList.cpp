
#include <stddef.h>
#include <stdint.h>

#include <list>

#include "ProblemFramework.h"

using namespace std;

// Ensure alignment and size are correct
static uint32_t s_ProblemList_memory[ (sizeof(ProblemList) + sizeof(uint32_t)) / sizeof(uint32_t) ] = { 0 };
static ProblemList *s_pProblemList_ptr = NULL;
ProblemList & ProblemList::instance()
{
    if( s_pProblemList_ptr == NULL ) {
        s_pProblemList_ptr = new( &s_ProblemList_memory[ 0 ] ) ProblemList();
    }

    return *s_pProblemList_ptr;
}

ProblemList::ProblemList() :
    m_problemList()
{
}

bool ProblemList::addProblem( const Problem &Prob )
{
    bool success = false;

    if( Prob.isValid() == true ) {
        m_problemList.push_back( Prob );
        success = true;
    }

    return success;
}

bool ProblemList::getProblemByNumber( Problem * const pProb, const uint32_t Number ) const
{
    bool success = false;

    if( (pProb != NULL)            &&
        (m_problemList.size() > 0) )
    {
        // Iterate over list
        for( list< Problem >::const_iterator iter = m_problemList.begin(); iter != m_problemList.end(); iter++ ) {
            // Find problem in list with matching number
            if( iter->getNumber() == Number ) {
                *pProb = *iter;
                success = true;
                break;
            }
        }
    }

    return success;
}