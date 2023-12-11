#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
void solve()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    int ans=0;
    if(b>a)ans++;
    if(c>a)ans++;
    if(d>a)ans++;
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}