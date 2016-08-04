
#include <stdint.h>

#include "ProblemFramework.h"

ProblemHook::ProblemHook( const uint32_t Number,
                          const Problem::Solution_t Solution )
{
    Problem prob( Number, Solution );

    ProblemList::instance().addProblem( prob );
}