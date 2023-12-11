/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
bitset<maxn>vis;
string p[maxn];
string mp[30][30];
int n,flag,ans;
void dfs(int x,int y)
{
	cout<<x<<" "<<y<<endl;
	if(flag)return ;
	if(x==n&&y==n)
	{
		flag=1;
		for(int i=1;i<=n*n-1;i++)
			if(!vis[i])ans=i;
		return ;
	}
	for(int i=1;i<=n*n-1;i++)
	{
		if(vis[i])continue;
		if(y==1&&p[i][3]!='0')continue;
		if(y==n&&p[i][1]!='0')continue;
		if(p[i][0]=='0'&&mp[x-1][y][2]!='0')continue;
		if(p[i][0]=='1'&&mp[x-1][y][2]!='2')continue;
		if(p[i][0]=='2'&&mp[x-1][y][2]!='1')continue;
		if(p[i][3]=='0'&&mp[x][y-1][1]!='0')continue;
		if(p[i][3]=='1'&&mp[x][y-1][1]!='2')continue;
		if(p[i][3]=='2'&&mp[x][y-1][1]!='1')continue;
		mp[x][y]=i;
		vis[i]=1;
		if(y==n)dfs(x+1,1);
		else dfs(x,y+1);
		vis[i]=0;
	}

}
void solve()
{
	cin>>n;
	for(int i=1;i<=n*n-1;i++)
		cin>>p[i];
	vis.reset();
	

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}