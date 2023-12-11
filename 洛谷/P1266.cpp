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
const int maxn=1e6+100;
struct node{
	int id,v;
	double dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct Edge{
	int to,next,v,l;
}edge[maxn];
int head[maxn],cnt;
vector<int>vv[200][600];
double dis[200][600];
bool vis[200][600];
int n,m,s=1,t,miv,mav;
double mi;
void add(int from,int to,int v,int l)
{
	edge[++cnt].v=v;
	edge[cnt].l=l;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij(int s,int sv)
{
	for(int i=1;i<=n;i++)
		for(int j=miv;j<=mav;j++)
			dis[i][j]=INF,vis[i][j]=0;
	priority_queue<node>q;
	q.push({s,sv,0});
	dis[s][sv]=0;
	vv[s][sv].push_back(s);
	mi=INF;
	int flv;
	while(!q.empty())
	{
		auto [x,xv,DIS]=q.top();q.pop();
		if(vis[x][xv])continue;
		vis[x][xv]=1;
		if(x==t){
			if(mi>DIS)
			{
				mi=DIS;
				flv=xv;
			}
		}
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int v=edge[i].v;
			int l=edge[i].l;
			int yv=(v==0?xv:v);
			if(dis[y][yv]>dis[x][xv]+1.0*l/yv)
			{
				dis[y][yv]=dis[x][xv]+1.0*l/yv;
				q.push({y,yv,dis[y][yv]});
				vv[y][yv]=vv[x][xv];
				vv[y][yv].push_back(y);
			}
		}
	}
	for(auto i:vv[t][flv])
		cout<<i-1<<" ";
	cout<<endl;
}
void solve()
{
	cin>>n>>m>>t;t++;
	miv=70,mav=70;
	for(int i=1;i<=m;i++)
	{
		int x,y,v,l;
		cin>>x>>y>>v>>l;
		add(x+1,y+1,v,l);
		miv=min(miv,v);
		mav=max(mav,v);
	}
	dij(s,70);
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