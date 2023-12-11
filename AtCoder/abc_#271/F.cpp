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
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,1,0,-1,1,-1,1,-1};
const int dy[]={1,0,-1,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int vis[22][22];
int mp[22][22];
int dp[22][22];
map<int,int>s[22][22];
map<int,int>t[22][22];
int n;
struct node{
	int x,y,fl;
};
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>mp[i][j];
	s[1][1][mp[1][1]]=1;
	int mid=n/2;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n+1-i+2;j++)
		{
			for(auto &[x,y]:s[i-1][j])
			{
				s[i][j][x^mp[i][j]]+=y;
			}
			for(auto &[x,y]:s[i][j-1])
			{
				s[i][j][x^mp[i][j]]+=y;
			}
		}
	}
	t[n][n][mp[n][n]]=1;
	for(int i=n;i>=1;i--)
	{
		for(int j=n;j>=min(1ll,n-(n-i)-2);j--)
		{
			for(auto &[x,y]:t[i+1][j])
			{
				t[i][j][x^mp[i][j]]+=y;
			}
			for(auto &[x,y]:t[i][j+1])
			{
				t[i][j][x^mp[i][j]]+=y;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int a=i;
		int b=n+1-i;
		for(auto [x,X]:s[a][b])
		{
			for(auto [y,Y]:t[a][b])
			{
				if((x^y)==0)ans+=X*Y;
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}