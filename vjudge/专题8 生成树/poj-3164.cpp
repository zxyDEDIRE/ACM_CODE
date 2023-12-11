#include<algorithm>
#include<iostream>
#include<math.h>
#include<queue>
#include<iomanip>
using namespace std;
#define endl "\n"
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=2e9+7;
const int maxn=1e6+100;
struct node{
	int x,y;double w;
}e[maxn];
int vis[maxn];
int pre[maxn];
double in[maxn];
int id[maxn];
int n,m,root;
double Edmonds()
{
	double ans=0;
	while(1)
	{
		for(int i=1;i<=n;i++)
			in[i]=INF;
		for(int i=1;i<=m;i++)
		{
			int x=e[i].x;
			int y=e[i].y;
			if(x!=y&&e[i].w<in[y])
				in[y]=e[i].w,pre[y]=x;
		}
		for(int i=1;i<=n;i++)
			if(i!=root&&in[i]==INF)
				return -1;
		int cnt=0;
		for(int i=1;i<=n;i++)
			vis[i]=id[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(i==root)continue;
			ans+=in[i];
			int v=i;
			while(vis[v]!=i&&!id[v]&&v!=root)
			{
				vis[v]=i;
				v=pre[v];
			}
			if(!id[v]&&v!=root)
			{
				id[v]=++cnt;
				for (int u=pre[v];u!=v;u=pre[u])
					id[u]=cnt;
			}
		}
		if(cnt==0)break;
		for(int i=1;i<=n;i++)
			if(!id[i])id[i]=++cnt;
		for(int i=1;i<=m;i++)
		{
			int u=e[i].x;
			int v=e[i].y;
			e[i].x=id[u];
			e[i].y=id[v];
			if(id[u]!=id[v])
				e[i].w-=in[v];
		}
		root=id[root];
		n=cnt;
	}
	return ans;
}
double a[maxn],b[maxn];
void solve()
{
	root=1;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(int i=1;i<=m;i++){
		cin>>e[i].x>>e[i].y;
		int x=e[i].x;
		int y=e[i].y;
		e[i].w=sqrt((a[x]-a[y])*(a[x]-a[y])+(b[x]-b[y])*(b[x]-b[y]));
	}
	double ans=Edmonds();
	if(ans==-1)cout<<"poor snoopy\n";
	else cout << fixed << setprecision(2) <<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	while(cin>>n>>m)
		solve();
	return 0;
}