#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
int a[maxn];
int b[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++)
		cin>>a[i],ans^=a[i];
	int mi=ans,ma=ans;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		if(n&1)ma|=b[i];
		else mi|=b[i],mi^=b[i];
	}
	cout<<mi<<" "<<ma<<endl;
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