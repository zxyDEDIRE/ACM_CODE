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
10
32524
14656
2377
8941
26549
6005
13407
9678
21225
31124

10
25546
15680
1363
31400
4399
3191
14004
6576
27092
29577

*/