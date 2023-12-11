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
const int maxn=10000;
bool vis[maxn];
int n;
void solve()
{
	int y1;
	cin>>y1;
	cin>>n;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		vis[x]=1;
	}
	int y2;
	cin>>y2;
	int ans=0;
	for(int i=y1;i<=y2;i++)
		if(!vis[i])ans++;
	cout<<ans<<endl;

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