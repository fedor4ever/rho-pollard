#include <iostream>
#include <assert.h>
#include "PO-pollard.hpp"

int main()
{

    std::cout << "Starting tests for GCD algorithm\n";
    std::cout << "Hello gcd:\t" << gcd(256,16) << "\n";
    std::cout << "Hello gcd:\t" << gcd(256,1) << "\n";

    std::cout << "Starting tests for rho-Pollard algorithm\n";
    std::cout << "\nTesting Po-Pollard with 4253:\t" << PoPollard(4253) << "\n"; //4253
    std::cout << "\nTesting Po-Pollard with 4256:\t" << PoPollard(4256) << "\n";
    std::cout << "\nTesting Po-Pollard with -79:\t" << PoPollard(-79) << "\n";
    std::cout << "\nTesting Po-Pollard with 0:\t" << PoPollard(0) << "\n";
    std::cout << "\nTesting Po-Pollard with 1:\t" << PoPollard(1) << "\n";
    std::cout << "\nTesting Po-Pollard with -1:\t" << PoPollard(-1) << "\n";

    return 0;
}
