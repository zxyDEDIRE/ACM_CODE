#include<bits/stdc++.h>
using namespace std;

string s;
const int N = 110;
bool vis[100];
int f[N][N];
int dp[N];
int n,ans;
void dfs(int x)
{
	if(x>=n)
	{
		// for(int i=0;i<=99;i++)
		// 	if(vis[i]){
		// 		cout<<i<<" ";
		// 	}
		// cout<<endl;
		ans++;
		return ;
	}
	int a=s[x]-'0';
	if(!vis[a])
	{
		vis[a]=1;
		dfs(x+1);
		vis[a]=0;
	}
	if(x+1<n&&a)
	{
		int b=a*10+s[x+1]-'0';
		if(!vis[b]&&b!=0)
		{
			vis[b]=1;
			dfs(x+2);
			vis[b]=0;
		}
	}
}
void solve(){
	n=s.size();
	ans=0;
	dfs(0);
	cout<<ans<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin>>s)
		solve();
	return 0;
}