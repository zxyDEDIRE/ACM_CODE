#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
void solve()
{
    int n,m,mia=INF,mib=INF,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m;
        vector<int>v(m,0);
        for(int j=0;j<m;j++)
            cin>>v[j];
        sort(v.begin(),v.end());
        ans+=v[1];
        mia=min(mia,v[0]);
        mib=min(mib,v[1]);
    }
    cout<<ans-mib+mia<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}