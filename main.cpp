#include <iostream>
#include <assert.h>
#include "PO-pollard.hpp"

int main()
{
    std::cout << "Hello gcd:" << gcd(256,16) << "\n";
    std::cout << "Testing Po-Pollard:" << PoPollard(-77) << "\n"; //4253
    return 0;
}
