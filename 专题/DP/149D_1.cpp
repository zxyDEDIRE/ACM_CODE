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
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=710;
int dp[N][N][5];
int p[N];
string str;
int n;
int dfs(int l,int r,int op)
{
	if(l==r-1)return dp[l][r][op]=1;
	if(dp[l][r][op]!=0)return dp[l][r][op];
	vector<pii>v;
	int now=l+1;
	while(now<r){
		v.push_back({now,p[now]});
		now=p[now]+1;
	}
	int DP[4];
	int last[4];
	for(int i=0;i<v.size();i++)
	{
		auto [x,y]=v[i];
		memset(DP,0,sizeof(DP));
		if(i==0)
		{
			DP[0]=dfs(x,y,0);
			DP[1]=dfs(x,y,1);
			if(op!=2) DP[2]=dfs(x,y,2);
			if(op!=3) DP[3]=dfs(x,y,3);
			DP[0]%=mod;
			DP[1]%=mod;
			DP[2]%=mod;
			DP[3]%=mod;
		}
		else
		{
			DP[0]+=(last[0]+last[1]+last[2]+last[3])*dfs(x,y,0);
			DP[1]+=(last[0]+last[1]+last[2]+last[3])*dfs(x,y,1);
			DP[2]+=(last[1]+last[2]+last[3])*dfs(x,y,2);
			DP[3]+=(last[0]+last[2]+last[3])*dfs(x,y,3);
			DP[0]%=mod;
			DP[1]%=mod;
			DP[2]%=mod;
			DP[3]%=mod;
		}
		for(int j=0;j<4;j++)
			last[j]=DP[j];
	}
	if(op!=0) dp[l][r][op]+=DP[0];dp[l][r][op]%=mod;
	if(op!=1) dp[l][r][op]+=DP[1];dp[l][r][op]%=mod;
	if(!(v.size()==1&&op==2))dp[l][r][op]+=DP[2];dp[l][r][op]%=mod;
	if(!(v.size()==1&&op==3))dp[l][r][op]+=DP[3];dp[l][r][op]%=mod;
	return dp[l][r][op];
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
	if(p[1]==n)
	{
		ans+=dfs(1,n,0);ans%=mod;
		ans+=dfs(1,n,1);ans%=mod;
		ans+=dfs(1,n,2);ans%=mod;
		ans+=dfs(1,n,3);ans%=mod;
	}
	else
	{
		ans+=dfs(0,n+1,4);
	}
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