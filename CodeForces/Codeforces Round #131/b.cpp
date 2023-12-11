/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn];
int n;
void solve()
{
    cin>>n;
    cout<<2<<endl;
    bitset<maxn>vis;
    p[1]=1;
    vis[1]=1;
    cout<<1<<" ";
    int j=2;
    for(int i=2;i<=n;i++)
    {
        if(vis[i])continue;
        int t=i;
        while(t<=n)
        {
            cout<<t<<" ";
            vis[t]=1;
            t*=2;
        }
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}