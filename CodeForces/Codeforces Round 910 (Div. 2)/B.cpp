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
int p[maxn];
int n;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    int cnt=0;
    int mi=p[n];
    for(int i=n-1;i>=1;i--)
    {
        int x=(p[i]+mi-1)/mi;
        cnt+=x-1;
        mi=(p[i]/x);
    }
    cout<<cnt<<endl;
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
/*
3
1 3 2

3 2
3 3 2
3 2
3 1 2 2
1 1 1 1 2 2
*/