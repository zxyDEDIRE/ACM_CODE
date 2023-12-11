/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,0,1,-1,1,-1,1,-1};
const int dy[]={0,1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=20;
bool vis[N][N];
int mp[N][N];
int n,m;
int f()
{
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int cnt=mp[i][j]==1;
			for(int k=0;k<5;k++)
				cnt+=vis[i+dx[k]][j+dy[k]];
			if(cnt&1)vis[i+1][j]=1;
		}
	}
	for(int j=1;j<=m;j++)
	{
		int cnt=(mp[n][j]==1);
		for(int k=0;k<5;k++)
			cnt+=vis[n+dx[k]][j+dy[k]];
		if(cnt&1)return -1;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cnt+=vis[i][j];
	return cnt;
}
string h(){
	string ans;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(vis[i][j])ans=ans+"1";
			else ans=ans+"0";
	return ans;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	int ans=INF;
	string res;
	for(int k=0;k<1<<m;k++)
	{
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=m;i++)
			if(k&(1<<(i-1)))vis[1][i]=1;
		int now=f();
		if(now==-1)continue;
		if(now<ans){
			ans=now;
			res=h();
		}
		else if(now==ans){
			string s=h();
			if(s<res)res=s;
		}
	}
	if(ans==INF)cout<<"IMPOSSIBLE"<<endl;
	else
	{
		for(int i=0;i<n*m;i++)
		{
			cout<<res[i]<<" ";
			if(i%m==m-1)cout<<endl;
		}
	}
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