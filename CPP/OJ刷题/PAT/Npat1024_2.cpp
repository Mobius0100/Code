/*
    分数的处理方法，
    最大公约数和最小公倍数
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Fraction {
    ll up,down;
};

char C[4] = {'+','-','*','/'};

ll gcd(ll a,ll b){
    return !b ? a : gcd(b,a%b);
}

ll lcm(ll a,ll b){
    return a / gcd(a,b) * b;
}

Fraction Reduction(Fraction result){
    if(result.down < 0){
        result.up = - result.up;
        result.down = - result.down;
    }

    if(result.up == 0) result.down = 1;
    else {
        int d = gcd(abs(result.down), abs(result.up));
        result.up /= d;
        result.down /= d;
    }

    return result;
}

Fraction add(Fraction a, Fraction b){
    Fraction ans;
    ans.up = a.up * b.down + a.down * b.up;
    ans.down = a.down * b.down;
    return Reduction(ans);
}

Fraction minu(Fraction a, Fraction b){
    Fraction ans;
    ans.up = a.up * b.down - a.down * b.up;
    ans.down = a.down * b.down;
    return Reduction(ans);
}

Fraction multi(Fraction a, Fraction b){
    Fraction ans;
    ans.up = a.up * b.up;
    ans.down = a.down * b.down;
    return Reduction(ans);
}

Fraction divide(Fraction a, Fraction b){
    Fraction ans;
    ans.up = a.up * b.down;
    ans.down = a.down * b.up;
    return Reduction(ans);
}

void outPut(Fraction result){
    if(result.up < 0) printf("(-");
    if(result.up == 0){
        printf("0");
        return ;
    }
    if(result.down == 1) printf("%lld",abs(result.up));
    else if(abs(result.up) > result.down) printf("%lld ",abs(result.up) / result.down);
    if(result.down != 1) printf("%lld/%lld",abs(result.up) % result.down, result.down);
    if(result.up < 0) printf(")");
}

int main()
{
    Fraction f1,f2,ans[4];

    scanf("%lld/%lld %lld/%lld",&f1.up,&f1.down,&f2.up,&f2.down);

    f1 = Reduction(f1);
    f2 = Reduction(f2);
    
    ans[0] = add(f1,f2);
    ans[1] = minu(f1,f2);
    ans[2] = multi(f1,f2);
    ans[3] = divide(f1,f2);

    for(int i=0;i<4;i++){
        outPut(f1);
        printf(" %c ",C[i]);
        outPut(f2);
        printf(" = ");
        if(i==3 && f2.up == 0){
            printf("Inf\n");
            continue;
        }
        outPut(ans[i]);
        printf("\n");
    }

    return 0;
}
