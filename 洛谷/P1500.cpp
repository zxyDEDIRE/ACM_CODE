/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
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
void MCMF(int s,int t)
{
	int maxf=0,maxc=0;
	while(spfa(s,t))
	{
		maxf+=flow[t];
		maxc+=flow[t]*dis[t];
		for(int i=t;i!=s;i=edge[last[i]^1].to)
		{
			edge[last[i]].w-=flow[t];
			edge[last[i]^1].w+=flow[t];
		}
	}
	cout<<maxf<<" "<<maxc<<endl;
}
const int N=100;
map<string,int>mp;
pii a[N],b[N];
int d[N][N];
int k;
double f(int x,int y){
	return 1.0*sqrt((a[x].first-b[y].first)*(a[x].first-b[y].first)+(a[x].second-b[y].second)*(a[x].second-b[y].second));
}
double h(int x,int y){
	if(a[x].first-b[y].first==0)return INF;
	else return 1.0*(a[x].second-b[y].second)/(a[x].first-b[y].first);

}
void solve()
{
	init();
	cin>>k;
	cin>>n;
	s=n*2+1;
	t=n*2+2;
	tot=t;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>a[i].first>>a[i].second>>str;
		mp[str]=i;
	}
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>b[i].first>>b[i].second>>str;
		mp[str]=i+n;
	}
	for(int i=1;i<=n*2;i++)
		for(int j=1;j<=n*2;j++)
			d[i][j]=1;
	string str_a,str_b;
	int w;
	while(cin>>str_a&&str_a!="End")
	{
		cin>>str_b>>w;
		int x=mp[str_a];
		int y=mp[str_b];
		if(x<=n&&y<=n)continue;
		if(x>n&&y>n)continue;
		if(x>y)swap(x,y);
		if(f(x,y-n)>k)continue;
		d[x][y]=max(d[x][y],w);
		d[y][x]=max(d[y][x],w);
		cout<<x<<" "<<y<<" "<<w<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int p=1;p<=n;p++)

			add(i,j+n,1,-d[i][j+n]);
			add(j+n,i,0,d[i][j+n]);
		}
		add(s,i,1,0);
		add(i,s,0,0);

		add(i+n,t,1,0);
		add(t,i+n,0,0);
	}
	MCMF(s,t);
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