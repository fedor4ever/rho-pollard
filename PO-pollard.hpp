#ifndef PO_POLLARD_HPP_INCLUDED
#define PO_POLLARD_HPP_INCLUDED

#include <iostream>
#include <assert.h>

template <typename T>
T gcd(T a, T b){
    static_assert(std::is_integral<T>::value, "Only integer types allowed");

    if(a<0) a=-a;
    if(b<0) b=-b;

    if(a%b==0) return b;
    if(b%a==0) return a;
    if(b==0) return (a>0)? a : -a;

    T c = 1;
    while((a%2 == 0)&&(b%2 == 0)){
        a>>=1;
        b>>=1;
        c<<=1;
    }

    while(a!=b){
        if(a%2 == 0)
            a>>=1;
        if(b%2 == 0)
            b>>=1;

        if(a>b)
            a-=b;
        if(b>a)
            b-=a;
    }
    return c*a;
}

template <typename T>
T fx(T x, T a, T c, T modN){
    auto tmp = (a*x*x + c)%modN;
//    assert(tmp==0); // for tested simple numbers always tmp==0
    return tmp;
}

template <typename T>
T PoPollard(T src){
    static_assert(std::is_integral<T>::value, "Only integer types allowed");
    T x1=2, x2=2, a=1, c=1, d=1;
    while(d==1){
        x1=fx(x1, a, c, src);
        x2=fx(fx(x2, a, c, src), a, c, src);

        if(x2==0) return 1; // looks like when src is simple number f(f(x))==0

        if(x1==x2){
            x1=2, x2=2;
            a++;
            continue;
        }

        d=gcd(abs(x1-x2), src);
        std::cout << "*"; // << d << "\n";
    }
    assert(src%d == 0);
    return d;
}

#endif // PO_POLLARD_HPP_INCLUDED
