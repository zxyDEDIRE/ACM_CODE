/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct Edge{
	int to,next,w,c;
}edge[maxn];
int head[maxn],cnt;
int dis[maxn],flow[maxn],last[maxn];
bitset<maxn>vis;
int n,m,s,t,tot;
void init(){
	memset(head+1,0,sizeof(int)*tot);
	cnt=1;
	tot=0;
}
void add(int from,int to,int w,int c)
{
	edge[++cnt].w=w;
	edge[cnt].c=c;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool spfa(int s,int t)
{
	memset(dis+1,INF,sizeof(int)*tot);
	memset(last+1,-1,sizeof(int)*tot);
	vis.reset();
	queue<int>q;
	q.push(s);
	dis[s]=0;
	vis[s]=1;
	flow[s]=INF;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=0;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			int c=edge[i].c;
			if(w>0&&dis[y]>dis[x]+c)
			{
				dis[y]=dis[x]+c;
				last[y]=i;
				flow[y]=min(flow[x],w);
				if(!vis[y])
					q.push(y),vis[y]=1;
			}
		}
	}
	return last[t]!=-1;
}
map<int,pii>mp;
vector<pii>v;
void MCMF(int s,int t)
{
	int num=0;
	int maxf=0,maxc=0;
	while(spfa(s,t))
	{
		maxf+=flow[t];
		maxc+=flow[t]*dis[t];
		for(int i=t;i!=s;i=edge[last[i]^1].to)
		{
			v.push_back(mp[i]);
			edge[last[i]].w-=flow[t];
			edge[last[i]^1].w+=flow[t];
		}
		num++;
		for(int i=v.size()-1;i>=3;i-=2)
		{
			int x=v[i].first;
			int y=v[i].second;
			int xx=v[i-2].first;
			int yy=v[i-2].second;
			if(xx>x)cout<<num<<" "<<0<<endl;
			else cout<<num<<" "<<1<<endl;
		}
		v.clear();
	}
}
const int N=50;
const int dx[]={0,1};
const int dy[]={1,0};

int ok[N][N];
int out[N][N];
int in[N][N];
int num;
void solve()
{
	cin>>num>>m>>n;
	init();
	s=++tot;
	t=++tot;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			out[i][j]=++tot;mp[tot]={i,j};
			in[i][j]=++tot;	mp[tot]={i,j};
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;cin>>x;
			if(x==0)
			{
				add(in[i][j],out[i][j],INF,0);
				add(out[i][j],in[i][j],0,0);
			}
			else if(x==2)
			{
				add(in[i][j],out[i][j],1,-1);
				add(out[i][j],in[i][j],0,1);

				add(in[i][j],out[i][j],INF,0);
				add(out[i][j],in[i][j],0,1);
			}
		}
	}
	add(s,in[1][1],num,0);
	add(in[1][1],s,0,0);

	add(out[n][m],t,INF,0);
	add(t,out[n][m],0,0);

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=0;k<2;k++){
				int x=i+dx[k];
				int y=j+dy[k];
				if(x>n||y>m)continue;
				add(out[i][j],in[x][y],INF,0);
				add(in[x][y],out[i][j],0,0);
			}
		}
	}

	MCMF(s,t);


}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}