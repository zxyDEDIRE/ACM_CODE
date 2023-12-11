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
int dp[111][255][255];
int mp[55][55];
int n,m;
int f(int x,int y){
	return m*(x-1)+y;
}
void to(int &a,int b){
	a=max(a,b);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
		}
	dp[3][f(1,2)][f(2,1)]=mp[1][2]+mp[2][1];
	for(int s=4;s<n+m;s++)
	{
		for(int a=1,b;a<=n;a++)
		{
			b=s-a;
			if(b<1||b>m)continue;
			for(int x=a+1,y;x<=n;x++)
			{
				y=s-x;
				if(y<1||y>m)continue;
				if(f(a-1,b)!=f(x-1,y))
					to(dp[s][f(a,b)][f(x,y)] ,dp[s-1][f(a-1,b)][f(x-1,y)]+mp[a][b]+mp[x][y]);
				if(f(a,b-1)!=f(x-1,y))
					to(dp[s][f(a,b)][f(x,y)] ,dp[s-1][f(a,b-1)][f(x-1,y)]+mp[a][b]+mp[x][y]);
				if(f(a-1,b)!=f(x,y-1))
					to(dp[s][f(a,b)][f(x,y)] ,dp[s-1][f(a-1,b)][f(x,y-1)]+mp[a][b]+mp[x][y]);
				if(f(a,b-1)!=f(x,y-1))
					to(dp[s][f(a,b)][f(x,y)] ,dp[s-1][f(a,b-1)][f(x,y-1)]+mp[a][b]+mp[x][y]);
			}
		}
	}
	// cout<<dp[n+m-1][f(n,m-1)][f(n-1,m)]<<endl;
	cout<<dp[n+m-1][f(n-1,m)][f(n,m-1)]<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
17+2+15
19
*/