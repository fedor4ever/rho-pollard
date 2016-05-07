#include <iostream>
#include <assert.h>
#include "PO-pollard.hpp"

int main()
{
    std::cout << "Hello gcd:" << gcd(256,16) << "\n";
    std::cout << "\nTesting Po-Pollard:" << PoPollard(4253) << "\n"; //4253
    return 0;
}
