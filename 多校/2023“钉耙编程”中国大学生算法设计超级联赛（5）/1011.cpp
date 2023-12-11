/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
bitset<maxn>vis;
vector<int>bcc;
stack<int>s;
int n,m,ans;
void init()
{
	for(int i=1;i<=n;i++)
	{
		dfn[i]=low[i]=col[i]=head[i]=0;
	}
	vis.reset();
	while(s.size())s.pop();
	cnt=1;
	tot=0;
	indx=0;
	ans=INF;
}
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
int f(int x)
{
	// cout<<"F "<<x<<endl;
	int fa=0;
	vector<int>w;
	int X=x;
	while(1)
	{
		vis[x]=1;
		int flag=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(col[y]!=col[X])continue;
			if(i==(fa^1))continue;
			if(vis[y]&&y!=X)continue;
			w.push_back(edge[i].w);
			x=edge[i].to;
			flag=0;
			fa=i;
			break;
		}
		if(flag)break;
	}
	for(auto x:bcc){
		vis[x]=0;
	}
	bcc.clear();
	if(w.size()==1)return w[0];
	else if(w.size()==2)return w[0]+w[1];
	else
	{
		sort(w.begin(),w.end());
		return min(w[0]+w[1],w[2]);
	}
	return 0;
}
void tarjan(int x,int fa)
{
	low[x]=dfn[x]=++indx;
	s.push(x);
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(!dfn[y])
		{
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x])
			{
				++tot;
				bcc.clear();
				bcc.push_back(x);
				col[x]=tot;
				int v;
				do{
					v=s.top();s.pop();
					col[v]=tot;
					bcc.push_back(v);
				}while(v!=y);
				ans=min(ans,f(x));
			}
		}
		else if(i!=(fa^1))
			low[x]=min(low[x],dfn[y]);
	}
}
void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	tarjan(1,0);
	cout<<ans<<endl;
}
signed main(){
	int size(512<<20); // 512M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size)); // YOUR CODE

 freopen("1011.in","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);

	int __;cin>>__;
	while(__--)
	{
		clock_t start, finish;
	start = clock();
	/*******代码*******/
	solve();
	/****************/
	finish = clock();
	cout << "the time cost is" <<\
	double(finish - start) / CLOCKS_PER_SEC<<endl;
}
//  fclose(stdin);
//  fclose(stdout);
	exit(0);
	return 0;
}