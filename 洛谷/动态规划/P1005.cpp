/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
const int N=111;
__int128 dp[N][N];
__int128 P=1;
int mp[N][N];
int n,m;
inline void write(__int128 x){
    if(x<0){
    	putchar('-');
		x=-x;
	}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
__int128 dfs(int x,int l,int r,int fl)
{
	if(l==r){
		return dp[l][r]=mp[x][l]*(P<<fl);
	}
	if(dp[l][r]!=0)return dp[l][r];
	__int128 a=dfs(x,l,r-1,fl+1)+mp[x][r]*(P<<fl);
	__int128 b=dfs(x,l+1,r,fl+1)+mp[x][l]*(P<<fl);
	dp[l][r]=max(a,b);
	return dp[l][r];
}

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	__int128 ans=0;
	for(int x=1;x<=n;x++)
	{
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				dp[i][j]=0;
		ans+=dfs(x,1,m,1);
	}
	write(ans);
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