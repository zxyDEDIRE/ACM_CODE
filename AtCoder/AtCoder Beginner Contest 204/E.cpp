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
#define pp(x) array<int,x>
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
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct Edge{
	int to,next,w,c;
}edge[maxn];
int head[maxn],cnt;
int dis[maxn];
int n,m;
void add(int from,int to,int c,int w){
	edge[++cnt].w=w;
	edge[cnt].c=c;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
int f(int t,int w)
{
	int x=floor(sqrt(w));
	int y=x+1;
	int mi;
	if(x+floor(w/(x+1))<y+floor(w/(y+1)))
		mi=x;
	else mi=y;
	if(t>mi)mi=t;
	return mi+floor(w/(mi+1));
}
void bfs(int s,int t)
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	bitset<maxn>vis;
	priority_queue<node>q;
	q.push({s,0});
	dis[s]=0;
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int c=edge[i].c;
			int w=edge[i].w;
			int mi=f(dis[x],w);
			if(dis[y]>mi+c){
			// cout<<x<<" "<<y<<" "<<c<<" "<<w<<" "<<mi<<" "<<dis[x]<<endl;
				dis[y]=mi+c;
				q.push({y,dis[y]});
			}
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,w,c;
		cin>>x>>y>>c>>w;
		add(x,y,c,w);
		add(y,x,c,w);
	}
	bfs(1,n);
	if(dis[n]==INF)cout<<-1<<endl;
	else cout<<dis[n]<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
t + x/t;

*/