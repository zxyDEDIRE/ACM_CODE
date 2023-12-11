/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
const int maxn=1e7+100;
namespace Flow{
	struct Edge{
		int to,next,w;
	}edge[maxn];
	int head[maxn],cnt=1;
	int dep[maxn];
	int s,t,tot;
	void init(){
		memset(head+1,0,sizeof(int)*tot);
		cnt=1;
		tot=0;
	}
	void add(int from,int to,int w)
	{
		edge[++cnt].w=w;
		edge[cnt].to=to;
		edge[cnt].next=head[from];
		head[from]=cnt;
	}
	void Add(int u,int v,int w)
	{
		add(u,v,w);
		add(v,u,0);
	}
	bool bfs(int s,int t)
	{
		memset(dep+1,0,sizeof(int)*tot);
		queue<int>q;
		dep[s]=1;
		q.push(s);
		while(!q.empty())
		{
			int x=q.front();q.pop();
			if(x==t)return true;
			for(int i=head[x];i;i=edge[i].next)
			{
				int y=edge[i].to;
				int w=edge[i].w;
				if(dep[y]==0&&w>0)
					q.push(y),dep[y]=dep[x]+1;
			}
		}
		return false;
	}
	int dfs(int x,int flow,int t)
	{
		if(x==t)return flow;
		int out=flow;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(w!=0&&dep[y]==dep[x]+1)
			{
				int tmp=dfs(y,min(out,w),t);
				edge[i].w-=tmp;
				edge[i^1].w+=tmp;
				out-=tmp;
				if(!out)break;
			}
		}
		if(out==flow)dep[x]=0;
		return flow-out;
	}
	int DINIC()
	{
		int ans=0;
		while(bfs(s,t))
			ans+=dfs(s,INF,t);
		return ans;
	}
}
const int N=1e3+10;
bitset<maxn>vis2;
bitset<maxn>vis1;
int in[N][N];
int n;
void solve()
{
	cin>>n;
	Flow::init();
	Flow::tot=n*2;
	Flow::s=++Flow::tot;
	Flow::t=++Flow::tot;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int x;cin>>x;
			if(x==0)continue;
			if(i==j)continue;
			if(!vis1[i])
			{
				vis1[i]=1;
				Flow::Add(Flow::s,i,1);
			}
			if(!vis2[j])
			{
				vis2[j]=1;
				Flow::Add(j+n,Flow::t,1);
			}
			int a=i;
			int b=j;
			if(a>b)swap(a,b);
			if(!in[a][b])
			{
				in[a][b]=++Flow::tot;
				++Flow::tot;
				Flow::Add(in[a][b],Flow::tot,1);
			}
			Flow::Add(i,in[a][b],1);
			Flow::Add(in[a][b]+1,j+n,1);
		}
	}
	cout<<Flow::DINIC()<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		clock_t start, finish;
	start = clock();
	/*******代码*******/
	solve();
	/****************/
	finish = clock();
	// cout << "the time cost is" <<\
	// double(finish - start) / CLOCKS_PER_SEC;
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
2
1 1
1 1


8
1 0 0 1 0 0 1 0
1 0 1 1 0 0 1 0
1 1 0 1 0 0 1 0 
1 0 1 1 0 1 0 0
1 0 1 0 0 0 1 0
1 0 1 0 1 0 1 0
0 1 0 1 0 1 0 0
1 0 1 1 0 0 1 0


7
0 0 0 0 0 0 1
1 0 0 0 0 0 0
1 1 0 0 0 0 0 
1 1 1 0 0 0 0 
1 1 1 1 0 0 0 
1 1 1 1 1 0 0 
0 1 1 1 1 1 0


3
0 1 0
0 0 1
1 0 0

7
0 1 1 1 1 1 0
0 0 1 1 1 1 1
0 0 0 1 1 1 1
0 0 0 0 1 1 1
0 0 0 0 0 1 0
0 0 0 0 0 0 1
0 0 0 0 1 0 0


1 2
1 3
2 3

1 2
2 3
3 1
*/