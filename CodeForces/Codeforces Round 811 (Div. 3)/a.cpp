
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll n,h,m;
void solve()
{
    int __;cin>>__;
    while(__--)
    {
        cin>>n>>h>>m;
        ll ans=1e18;
        for(int i=1;i<=n;i++)
        {
            ll x,y;
            cin>>x>>y;
            ans=min((x*60+y-h*60-m+24*60)%(24*60),ans);
        }
        cout<<ans/60<<" "<<ans%60<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}