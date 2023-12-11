/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
bool vis[maxn];
int p[10];
char mp[100][100];
string str;
int n,m;
int sx,sy;
int tx,ty;
int cnt=0;
int check()
{
	int x=sx;
	int y=sy;
	for(auto i:str)
	{
		int fl=p[i-'0'];
		x=x+dx[fl];
		y=y+dy[fl];
		if(x==tx&&y==ty)return 1;
		if(mp[x][y]=='#')return 0;
		if(x<1||y<1||x>n||y>m)return 0;
	}
	return 0;
}
void dfs(int step)
{
	if(step==4)
	{
		cnt=cnt+check();
		return ;
	}
	for(int i=0;i<4;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		p[step]=i;
		dfs(step+1);
		vis[i]=0;
	}
}
void solve()
{
	cin>>n>>m;
	cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			if(mp[i][j]=='S')sx=i,sy=j;
			if(mp[i][j]=='E')tx=i,ty=j;
		}
	}
		
	cin>>str;
	dfs(0);
	cout<<cnt<<endl;
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
/*

*/