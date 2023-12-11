#include<bits/stdc++.h>
using namespace std;
using LL=__int128;
using ll=long long;
LL n;
LL get1(LL l,LL r,LL n){
    return (l+r)*(n)/2;
}
inline void write(LL x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+'0');
}  
void solve()
{
    LL n;
    ll _n;
    cin>>_n;
    n=_n;
    LL ans=0;
    if(n%2==0)
    {
        LL tp=5;
        while(n>=tp){
            LL num=n/tp;
            LL n1=(num+1)/2,n2=num/2;
            LL ce1=n/2-((tp+1)/2)+1,ce2=(n/2-(tp*2ll+1)/2+1);            
            LL d=-tp;
            if(n1)
            ans+=get1(ce1+(n1-1)*d,ce1,n1);
            if(n2)
            ans+=get1(ce2+d*(n2-1),ce2,n2);
            tp*=5ll;
        }
    }
    else
    {
        LL tp=5;
        while(n>=tp){
            LL num=n/tp;
            LL n1=(num+1)/2,n2=(num)/2;
            LL ce1=n/2-((tp)/2)+1,ce2=(n/2-(tp*2ll)/2+1);            
            LL d=-tp;
            if(n1)
            ans+=get1(ce1+(n1-1)*d,ce1,n1);
            if(n2)
            ans+=get1(ce2+d*(n2-1),ce2,n2);
            tp*=5ll;
        }
    }
    write(ans);
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    solve();
	return 0;
}
/*
1000000000000000000
62499999999999993747901916503906245
*/