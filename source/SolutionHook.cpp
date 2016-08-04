
#include <stdint.h>

#include "SolutionFramework.h"

SolutionHook::SolutionHook( const uint32_t Number,
                          const Solution::SolutionFn_t SolutionFn )
{
    Solution soln( Number, SolutionFn );

    SolutionList::instance().addSolution( soln );
}