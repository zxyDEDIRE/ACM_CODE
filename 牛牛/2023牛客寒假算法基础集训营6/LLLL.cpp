#include <stdio.h>
const int M = 2e5+10;
int ff[M+5];  //打表，记录n!，避免重复计算
 
//求最大公因数
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
 
//解线性同余方程，扩展欧几里德定理
int x,y;
void Extended_gcd(int a,int b)
{
    if(b==0)
    {
        x=1;
        y=0;
    }
    else
    {
        Extended_gcd(b,a%b);
        long t=x;
        x=y;
        y=t-(a/b)*y;
    }
}
 
//计算不大的C(n,m)
int C(int a,int b)
{
    if(b>a)
        return 0;
    b=(ff[a-b]*ff[b])%M;
    a=ff[a];
    int c=gcd(a,b);
    a/=c;
    b/=c;
    Extended_gcd(b,M);
    x=(x+M)%M;
    x=(x*a)%M;
    return x;
}
 
//Lucas定理
int Combination(int n, int m)
{
    int ans=1;
    int a,b;
    while(m||n)
    {
        a=n%M;
        b=m%M;
        n/=M;
        m/=M;
        ans=(ans*C(a,b))%M;
    }
    return ans;
}
 
int main()
{
    int i,m,n;
    ff[0]=1;
    for(i=1; i<=M; i++) //预计算n!
        ff[i]=(ff[i-1]*i)%M;
    while(~scanf("%d%d",&n, &m))
    {
        printf("%d\n",Combination(n,m));
    }
    return 0;
}
