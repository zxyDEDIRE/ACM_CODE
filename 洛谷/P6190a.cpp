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
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e18+7;
const int maxn=1e6+100;
struct node{
	int x,y,w;
}e[maxn];
struct E{
	int e[111][111];
	int n;
}a;
E operator*(const E &x,const E &y)
{
	E z;
	z.n=x.n;
	for(int i=1;i<=z.n;i++)
		for(int j=1;j<z.n;j++)
			z.e[i][j]=INF;
	for(int k=1;k<=z.n;k++)
		for(int i=1;i<=z.n;i++)
			for(int j=1;j<=z.n;j++)
				z.e[i][j]=min(z.e[i][j],x.e[i][k]+y.e[k][j]);
	return z;
}
int dis[111][111];
int n,m,t;
E fp(E x,int p)
{
	E r,d(x);
	r.n=x.n;
	for(int i=1;i<=r.n;i++)
		for(int j=1;j<=r.n;j++)
			r.e[i][j]=dis[i][j];
	while(p)
	{
		if(p&1)r=r*d;
		d=d*d;
		p>>=1;
	}
	return r;
}
void solve()
{
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				dis[i][j]=INF;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		e[i]={x,y,w};
		dis[x][y]=w;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	if(t)
	{
		a.n=n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a.e[i][j]=dis[i][j];
		for(int k=1;k<=m;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					a.e[i][j]=min(a.e[i][j],dis[i][e[k].x]+dis[e[k].y][j]-e[k].w);
				}
			}
		}
		E ans=fp(a,t);
		cout<<ans.e[1][n]<<endl;
	}
	else cout<<dis[1][n]<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}