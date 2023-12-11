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
const int N=710;
int dp[N][N][3][3];
int p[N];
string str;
int n;
int dfs(int l,int r,int opl,int opr)
{
	if(l==r-1)return dp[l][r][opl][opr]=1;
	if(dp[l][r][opl][opr]!=0)return dp[l][r][opl][opr];
	vector<pii>v;
	int now=l+1;
	while(now<r)
	{
		v.push_back({now,p[now]});
		now=p[now]+1;
	}
	int DP[3][3];
	int last[3][3];
	for(int i=0;i<v.size();i++)
	{
		auto [x,y]=v[i];
		memset(DP,0,sizeof(DP));
		if(i==0)
		{
			DP[0][1]=dfs(x,y,0,1);
			DP[0][2]=dfs(x,y,0,2);
			if(opl!=1) DP[1][0]=dfs(x,y,1,0);
			if(opl!=2) DP[2][0]=dfs(x,y,2,0);
			// cout<<DP[0][1]<<" "<<DP[0][2]<<" "<<DP[1][0]<<" "<<DP[2][0]<<endl;
			DP[0][1]%=mod;
			DP[0][2]%=mod;
			DP[1][0]%=mod;
			DP[2][0]%=mod;
		}
		else
		{
			DP[0][1]+=(last[0][1]+last[0][2]+last[1][0]+last[2][0])*dfs(x,y,0,1);
			DP[0][2]+=(last[0][1]+last[0][2]+last[1][0]+last[2][0])*dfs(x,y,0,2);
			DP[1][0]+=(last[0][2]+last[1][0]+last[2][0])*dfs(x,y,1,0);
			DP[2][0]+=(last[0][1]+last[1][0]+last[2][0])*dfs(x,y,2,0);
			DP[0][1]%=mod;
			DP[0][2]%=mod;
			DP[1][0]%=mod;
			DP[2][0]%=mod;
			// cout<<DP[0][1]<<" "<<last[0][1]+last[0][2]+last[0][2]<<" "<<dfs(x,y,0,1)<<endl;
			// cout<<DP[0][2]<<" "<<last[0][1]+last[1][0]+last[2][0]<<" "<<dfs(x,y,0,2)<<endl;
			// cout<<DP[1][0]<<" "<<last[0][2]+last[1][0]+last[2][0]<<" "<<dfs(x,y,1,0)<<endl;
			// cout<<DP[2][0]<<" "<<last[0][1]+last[1][0]+last[2][0]<<" "<<dfs(x,y,2,0)<<endl;
		}
		for(int a=0;a<3;a++)
			for(int b=0;b<3;b++)
				last[a][b]=DP[a][b];
	}
	if(opr!=1) dp[l][r][opl][opr]+=DP[0][1];dp[l][r][opl][opr]%=mod;
	if(opr!=2) dp[l][r][opl][opr]+=DP[0][2];dp[l][r][opl][opr]%=mod;
	if(!(v.size()==1&&opl==1))dp[l][r][opl][opr]+=DP[1][0];dp[l][r][opl][opr]%=mod;
	if(!(v.size()==1&&opl==2))dp[l][r][opl][opr]+=DP[2][0];dp[l][r][opl][opr]%=mod;
	// cout<<dp[l][r][opl][opr]<<endl;
	return dp[l][r][opl][opr];
}
void solve()
{
	cin>>str;
	n=str.size();
	stack<int>s;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='(')s.push(i+1);
		else
		{
			int x=s.top();
			p[x]=i+1;
			p[i+1]=x;
			s.pop();
		}
	}
	int ans=0;
	ans+=dfs(1,n,0,1);ans%=mod;
	ans+=dfs(1,n,0,2);ans%=mod;
	ans+=dfs(1,n,1,0);ans%=mod;
	ans+=dfs(1,n,2,0);ans%=mod;
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
/*
1 2 0 0
1 0 1 0
1 0 2 0
*/