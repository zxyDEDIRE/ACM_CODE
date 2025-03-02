# E [ 干饭豪的不定方程](https://ac.nowcoder.com/acm/contest/72386/E)

出题人:爆哥

考察点:暴力枚举

对于 $n<=10^9,a,t,b,k\geq2$ 那么我们可以发现单暴力枚举 $x^y$ 这种形式不会有很多,所以我们可以先预处理出来这些情况方案之后，在对于每个询问，枚举 $b^k$ 来看之前多少种 $a^t=n-b^k$ 情况

~~~cpp
/*
干饭豪的a^k+b^t=n
数据未更新
*/
/*
    有多少个四元组(a,t,b,k)满足下面式子
    a^t+b^k=n
    且a,b,t,k>=2
    n<=1e9
*/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    long long ans=0;
    map<long long,int>mp;
    mp.clear();

    for(int a=2;;a++){
        long long c=1ll*a*a;
        if(c>=n) break;
        for(int t=2;c<n;t++,c=c*a){
            mp[c]++;
        }
    }
    for(int a=2;;a++){
        long long c=1ll*a*a;
        if(c>=n) break;
        for(int t=2;c<n;t++,c=c*a){
            if(mp.count(n-c)){
                ans+=mp[n-c];
            }
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
*/
~~~

