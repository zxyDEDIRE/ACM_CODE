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
int dp[maxn];
int p[maxn];
int col[maxn];
bool vis[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int tot=0;
	dp[0]=INF;
	for(int i=1;i<=n;i++)
	{
		if(p[i]<dp[tot])dp[++tot]=p[i],col[p[i]]=tot;
		else
		{
			int fl=lower_bound(dp+1,dp+1+tot,p[i],greater<int>())-dp;
			col[p[i]]=col[dp[fl]];
			dp[fl]=p[i];
		}
	}
	cout<<tot<<endl;
	for(int i=1;i<=n;i++)
		cout<<col[p[i]]<<" ";cout<<endl;
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
4
1 3 2 4

5
1 4 2 5 3
*/