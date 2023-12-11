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
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<vector<int>>v;
int dp[5011][400];
bool vis[400][400];
vector<int>p(8,0);
int n,m;
void dfs(int step)
{
	if(step==m){
		v.push_back(p);
		return ;
	}
	if(step==0){
		p[step]=0;dfs(step+1);
		p[step]=1;dfs(step+1);
		p[step]=2;dfs(step+1);
	}
	else{
		if(p[step-1]!=0)p[step]=0,dfs(step+1);
		if(p[step-1]!=1)p[step]=1,dfs(step+1);
		if(p[step-1]!=2)p[step]=2,dfs(step+1);
	}
}
void solve()
{
	cin>>m>>n;
	dfs(0);
	for(int i=0;i<v.size();i++){
		for(int j=i;j<v.size();j++){
			int flag=0;
			for(int k=0;k<m;k++)
				if(v[i][k]==v[j][k])flag=1;
			vis[i][j]=vis[j][i]=flag;
		}
	}
	m=v.size();
	for(int i=0;i<m;i++)
		dp[1][i]=1;
	for(int i=2;i<=n;i++)
		for(int j=0;j<m;j++)
			for(int k=0;k<m;k++)
				if(!vis[j][k])
					(dp[i][j]+=dp[i-1][k])%=mod;
	int ans=0;
	for(int i=0;i<m;i++)
		(ans+=dp[n][i])%=mod;
	cout<<ans<<endl;
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