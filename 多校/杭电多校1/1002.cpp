/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const int maxn=20;
int mp[maxn][maxn][maxn][maxn];
bool vis[maxn][maxn];
bool val[maxn];
int n,m,k,res=1e9;
int sx,sy,tx,ty;
void dfs(int x,int y,int ans)
{
	if(ans>res)return ;
	if(x==tx&&y==ty){
		res=min(res,ans);
		//cout<<res<<endl;
		return ;
	}
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		int fl=0;
		if(xx<0||yy<0||xx>n||yy>m)continue;
		if(vis[xx][yy])continue;
		int t=mp[x][y][xx][yy];
		if(val[t])fl=1,val[t]=0;
		vis[xx][yy]=1;
		//if(fl)cout<<x<<" "<<y<<" "<<xx<<" "<<yy<<endl;
		dfs(xx,yy,ans+fl);
		vis[xx][yy]=0;
		if(t)val[t]=1;
	}

}
void solve()
{
	cin>>n>>m>>k;
	cin>>sx>>sy>>tx>>ty;
	res=1e9;
	memset(mp,0,sizeof(mp));
	for(int i=1;i<=k;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a==c)
		{
			for(int j=min(b,d);j<=max(b,d);j++)
				mp[a][j][a-1][j]=mp[a-1][j][a][j]=i;
		}
		else
		{
			for(int j=min(a,c);j<=max(a,c);j++)
				mp[j][b][j][b-1]=mp[j][b-1][j][b]=i;
		}
		val[i]=1;
	}
	
	vis[sx][sy]=1;
	dfs(sx,sy,0);
	cout<<res<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
1 2 3 3 3 3
*/