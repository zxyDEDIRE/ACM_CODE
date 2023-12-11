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
bool vis[10][10];
int mp[10][10];
int p[100];
vector<pii>v;
int n=4,cnt;
int f(int x,int y){
	return (x-1)*4+y;
}
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
bool check()
{
	for(int i=1;i<=17;i++)
		p[i]=i;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
			if(mp[i][j]&&!vis[i][j])return 0;
			if(i+1<=n&&vis[i+1][j]==vis[i][j])
			{
				int fa=find(f(i,j));
				int fb=find(f(i+1,j));
				if(fa!=fb)p[fa]=fb;
			}
			if(j+1<=n&&vis[i][j+1]==vis[i][j])
			{
				int fa=find(f(i,j));
				int fb=find(f(i,j+1));
				if(fa!=fb)p[fa]=fb;
			}
			if(!vis[i][j])
			{
				int fa=find(f(5,1));
				int fb=find(f(i,j));
				p[fb]=fa;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=17;i++)
		if(find(i)==i)cnt++;
	return cnt==2;
}
void dfs(int x,int y)
{
	if(x==4&&y==4)
	{
		if(check())cnt++;
		return ;
	}
	int xx=x;
	int yy=y;
	if(y==4)xx=x+1,yy=1;
	else xx=x,yy=y+1;

	dfs(xx,yy);
	vis[xx][yy]=1;
	dfs(xx,yy);
	vis[xx][yy]=0;
}
void solve()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>mp[i][j];
			if(mp[i][j])
				v.push_back({i,j});
		}
	dfs(1,1);
	vis[1][1]=1;
	dfs(1,1);
	cout<<cnt<<endl;
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
4
3*2
10
4

240

*/