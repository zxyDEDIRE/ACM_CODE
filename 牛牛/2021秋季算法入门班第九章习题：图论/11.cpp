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
const int INF=1e9+7;
const int maxn=1e6;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int depa[maxn];
int depb[maxn];
int f1=0,d1=0;
int f2=0,d2=0;
int n;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dfs1(int x,int fa)
{
	if(depa[x]>d1)
	{
		d1=depa[x];
		f1=x;
	}
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==fa)continue;
		depa[y]=depa[x]+edge[i].w;
		dfs1(y,x);
	}
}
void dfs2(int x,int fa)
{
	if(depa[x]>d2)
	{
		d2=depa[x];
		f2=x;
	}
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==fa)continue;
		depa[y]=depa[x]+edge[i].w;
		dfs2(y,x);
	}

}
void dfs3(int x,int fa)
{

	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==fa)continue;
		depb[y]=depb[x]+edge[i].w;
		dfs3(y,x);
	}
}
void solve()
{
	// cin>>n;
	while(cin>>n)
	{
		memset(head+1,0,sizeof(int)*cnt);
		cnt=0;
		for(int i=1;i<n;i++)
		{
			int x,y,w;
			cin>>x>>y>>w;
			add(x,y,w);
			add(y,x,w);
		}
		
		d1=d2=-1;
		dfs1(1,0);
		memset(depa+1,0,sizeof(int)*n);
		dfs2(f1,0);
		dfs3(f2,0);
		int ans=0;
		// cout<<f1<<" "<<f2<<endl;
		// for(int i=1;i<=n;i++)
		// 	cout<<depa[i]<<" ";cout<<endl;
		// for(int i=1;i<=n;i++)
		// 	cout<<depb[i]<<" ";cout<<endl;


		for(int i=1;i<=n;i++)
			ans+=max(depa[i],depb[i]);
		cout<<ans-depa[f2]<<endl;
		memset(depa+1,0,sizeof(int)*n);
		memset(depb+1,0,sizeof(int)*n);
	}
	
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}