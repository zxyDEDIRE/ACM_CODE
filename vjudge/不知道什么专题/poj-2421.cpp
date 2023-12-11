/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
#define endl "\n"
const int maxn=111;
struct node{
	int x,y,w;
}a[2000000];
bool vis[maxn][maxn];
int mp[maxn][maxn];
int p[maxn];
int n,m;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>mp[i][j];
	int q,sum=0,cnt=0;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		//x++,y++;
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)p[fb]=fa;
		//sum+=mp[x][y];
		vis[x][y]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			// if(i==j)continue;
			// if(vis[i][j])continue;
			cnt++;
			a[cnt].x=i;
			a[cnt].y=j;
			a[cnt].w=mp[i][j];
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int fa=find(a[i].x);
		int fb=find(a[i].y);
		if(fa!=fb)
		{
			p[fb]=fa;
			sum+=a[i].w;
		}
	}
	cout<<sum<<endl;
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
		solve();
	return 0;
}