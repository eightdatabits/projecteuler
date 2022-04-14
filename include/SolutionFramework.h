
#include <stdint.h>

#include <list>

#define ADD_SOLUTION(num,soln) static SolutionHook s_Solution_##num( (num), (soln) )


class Solution
{
public:
    typedef void (*SolutionFn_t)( void );

    Solution();
    Solution( const uint32_t Number,
             const SolutionFn_t Solution );
    ~Solution() {};

    uint32_t getNumber() const;
    bool run() const;

    bool isValid() const;

private:

    uint32_t m_number;
    SolutionFn_t m_solutionFn;
};


class SolutionList
{
public:
    // Get singleton instance
    static SolutionList & instance();

    bool addSolution( const Solution &Soln );
    bool getSolutionByNumber( Solution *const pSoln, const uint32_t Number ) const;

private:
    // Singleton class, so make these private
    SolutionList();
    SolutionList( const SolutionList & );
    SolutionList & operator =( const SolutionList & );
    ~SolutionList() {};

    std::list< Solution > m_SolutionList;
};


class SolutionHook
{
public:
    SolutionHook( const uint32_t Number,
                 const Solution::SolutionFn_t Solution );
    ~SolutionHook() {};
};