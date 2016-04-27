#include <iostream>
#include <assert.h>

template <typename T>
T gcd(T a, T b){
    static_assert(std::is_integral<T>::value, "Only integer types allowed");
    if(a<0) a=-a;
    if(b<0) b=-b;

    T c = 1;
    while((a%2 == 0)&&(b%2 == 0)){
        a>>=1;
        b>>=1;
        c<<=1;
    }

    while(a!=b){
        if(a%b==0)
            return c*b;
        if(b%a==0)
            return c*a;
        if(a%2 == 0)
            a=a>>1;
        if(a>b)
            a=(a-b);
        if(b>a)
            b=(b-a);
        if(b%2 == 0)
            b=b>>1;
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

        d=gcd(abs(x1)-abs(x2), src);
    }
    return src/d;
}

int main()
{
    std::cout << "Hello gcd:" << gcd(256,16) << "\n";
    std::cout << "Testing Po-Pollard:" << PoPollard(-77) << "\n"; //4253
    return 0;
}
