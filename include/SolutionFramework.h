
#include <stdint.h>

#include <list>

#define ADD_PROBLEM(num,soln) static ProblemHook s_Problem_##num( (num), (soln) )


class Problem
{
public:
    typedef void (*Solution_t)( void );

    Problem();
    Problem( const uint32_t Number,
             const Solution_t Solution );
    ~Problem() {};

    uint32_t getNumber() const;
    Solution_t getSolution() const;

    bool isValid() const;

private:

    uint32_t m_number;
    Solution_t m_solution;
};


class ProblemList
{
public:
    // Get singleton instance
    static ProblemList & instance();

    bool addProblem( const Problem &Prob );
    bool getProblemByNumber( Problem *const pProb, const uint32_t Number ) const;

private:
    // Singleton class, so make these private
    ProblemList();
    ProblemList( const ProblemList & );
    ProblemList & operator =( const ProblemList & );
    ~ProblemList() {};

    std::list< Problem > m_problemList;
};


class ProblemHook
{
public:
    ProblemHook( const uint32_t Number,
                 const Problem::Solution_t Solution );
    ~ProblemHook() {};
};