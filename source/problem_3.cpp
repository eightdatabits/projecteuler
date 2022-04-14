
#include <stdint.h>
#include <array>
#include <iostream>

#include "SolutionFramework.h"

bool isPrime(int64_t num) {
    for(int64_t i = 2; i <= num/2; i++) {
        if (num % i == 0) {
            // num is not prime
            return false;
        }
    }
    return true;
}

int64_t nextPrime(int64_t current) {
    int64_t candidate = current + 1;
    while(!isPrime(candidate)) {
        candidate++;
    }
    return candidate;
}

/*
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 */
void problem_3_solution()
{
    static constexpr int64_t NUMBER = 600851475143;

    std::cout << "Prime factors: ";
    
    int64_t div = 2;
    while (div <= NUMBER/2) {
        div = nextPrime(div);
        if (NUMBER % div == 0) {
            std::cout << div << " ";
            std::cout.flush();
        }
    }
    std::cout << "No prime factors found" << std::endl;
}

ADD_SOLUTION( 3, problem_3_solution );
