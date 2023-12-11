/*！*/
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=10000005;
const int maxn=1e7+10;
const int N=1e7+10;
struct Edge{int to,next,w;}edge[N];
int head[N],_cnt;
int del[N],siz[N],maxson,root,sum;
ll dis[N],d[N],cnt;
ll ans[N],q[maxn],judge[maxn],ask[maxn];
int n,m;
ll W[maxn];
void add(int from,int to,int w){
	edge[++_cnt].w=w;
	edge[_cnt].to=to;
	edge[_cnt].next=head[from];
	head[from]=_cnt;
}
void getroot(int x,int fa)
{
	siz[x]=1;
	int sx=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==fa||del[y])continue;
		getroot(y,x);
		siz[x]+=siz[y];
		sx=max(sx,siz[y]);
	}
	sx=max(sx,sum-siz[x]);
	if(sx<maxson)maxson=sx,root=x;
}
void getdis(int x,int fa)
{
	dis[++cnt]=d[x];
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==fa||del[y])continue;
		d[y]=d[x]+W[y];
		getdis(y,x);
	}
}
void calc(int x,ll w,int op)
{
	cnt=0,d[x]=w;
	getdis(x,0);

	for(int i=1;i<=m;i++)
	{
		map<int,int>ok;
		for(int j=1;j<=cnt;j++)
		{
			if(ok.count(W[x]-dis[j]))
				ans[i]+=op*ok[W[x]-dis[j]];
			ok[dis[j]]++;
		}
	}
}
void divide(int x)
{
	calc(x,W[x],1);
	del[x]=1;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(del[y])continue;
		calc(y,W[x]+W[y],-1);
		maxson=sum=siz[y];
		getroot(y,0);
		divide(root);
	}
}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char ch;cin>>ch;
		if(ch=='a')W[i]=inf;
		else if(ch=='b')W[i]=1;
		else W[i]=-inf-1;
	}
	for(int i=1;i<n;i++)
	{
		int x,y,w;
		cin>>x>>y;
		add(x,y,0);
		add(y,x,0);
	}
	ask[++m]=0;
	maxson=sum=n;
	getroot(1,0);
	getroot(root,0);

	// cout<<"root "<<root<<endl;

	divide(root);
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<endl;
}
signed main(){
	int size(512<<20); // 512M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size)); // YOUR CODE
 freopen("1004.in","r",stdin);
 // freopen("out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	// return 0;
	exit(0);
}