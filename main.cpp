#include <stdio.h>
#include <assert.h>

long gcd(long a, long b){
    printf("step1\n");
    if(a<0) a=-a;
    if(b<0) b=-b;

    long c = 1;
    while((a%2 == 0)&&(b%2 == 0)){
        printf("step2\n");
        a=a>>1;
        b=b>>1;
        c*=2;
    }
    printf("step3\n");
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

long fx(long x, long a, long c, long modN){
    auto tmp = (a*x*x + c)%modN;
//    assert(tmp==0); // for tested simple numbers always tmp==0
    return tmp;
}

long PoPollard(long src){
    long x1=2, x2=2, a=1, c=1, d=1;
    while(d==1){
        x1=fx(x1, a, c, src);
        printf("x1 is:%ld\n",x1);
        x2=fx(fx(x2, a, c, src), a, c, src);
        printf("x2 is:%ld\n",x2);

        if(x2==0) return 1; // looks like when src is simple number f(f(x))==0

        if(x1==x2){
            x1=2, x2=2;
            a++;
            continue;
        }

        d=gcd(abs(x1)-abs(x2), src);
        printf("d is: %ld\n", d);
    }
    return src/d;
}

int main()
{
//    printf("Hello world! %ld\n", gcd(256,16));
    printf("Testing Po-Pollard: %ld\n", PoPollard(4253));
    return 0;
}
