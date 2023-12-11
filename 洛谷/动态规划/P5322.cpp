/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[111];
vector<pii>w[111];
int dp[maxn];
int s,n,m;
void solve()
{
	cin>>s>>n>>m;
	for(int j=1;j<=s;j++)
	{
		for(int i=1;i<=n;i++)
		{
			int x;cin>>x;
			v[i].push_back(x);
		}
	}
	for(int i=1;i<=m;i++)
		dp[i]=-1;

	for(int x=1;x<=n;x++)
	{
		sort(v[x].begin(),v[x].end());
		for(int j=m;j>=0;j--)
		{
			for(int i=0;i<s;i++)
				if(j>=v[x][i]*2+1)
					dp[j]=max(dp[j],dp[j-(v[x][i]*2+1)]+(i+1)*x);
		}
	}
	int ma=0;
	for(int i=1;i<=m;i++)
		ma=max(ma,dp[i]);
	cout<<ma<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
*/