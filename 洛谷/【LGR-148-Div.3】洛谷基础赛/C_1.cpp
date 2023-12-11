
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

const int INF=1e9+7;
const int N=8e4+1;
const int maxn=2e4+1;
struct Edge{
	int to,w,next;
}edge[N];
struct node{
	int id,k,hp;
	bool operator<(const node&a)const{
		return a.hp<hp;
	}
};
int head[maxn],cnt;
map<int,int>dis[maxn];
map<int,bool>vis[maxn];
int n,m,s,t;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
inline void dij()
{
	priority_queue<node>q;
	q.push({t,0,0});
	dis[t][0]=0;
	while(!q.empty())
	{
		auto [x,k,hp]=q.top();q.pop();
		if(x==s){
			cout<<hp<<endl;
			return ;
		}
		if(vis[x].count(k))continue;
		// cout<<x<<" "<<k<<" "<<hp<<endl;
		vis[x][k]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			int _k=k+1;
			int _hp=dis[x][k]+(w/_k);
			if(_k>n)continue;
			if(!dis[y].count(_k)||dis[y][_k]>_hp)
			{
				dis[y][_k]=_hp;
				q.push({y,_k,dis[y][_k]});
			}
		}
	}
	// cout<<"SDf"<<endl;
	int mi=INF;
	for(int i=1;i<=n;i++)
		if(dis[s].count(i))
			mi=min(mi,dis[s][i]);
	cout<<mi<<endl;
}
void solve()
{
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	dij();
	

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*

*/