#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
const int maxn=1e6+10;
class Edmonds{
public:
	struct node{int x,y,w;}p[maxn];
	int vis[maxn],pre[maxn],in[maxn],id[maxn];
	int n,m,root,cnt,pos;
	Edmonds(){}
	void init(int _n){
		n=_n;m=0;pos=0;
	}
	void add(int x,int y,int w){
		p[++m]={x,y,w};
	}
	int run(int _root){
		root=_root;
		int ans=0;
		while(1){
			for(int i=1;i<=n;i++)in[i]=INF;
			for(int i=1;i<=m;i++){
				auto [x,y,w]=p[i];
				if(x!=y&&w<in[y]){
					in[y]=w,pre[y]=x;
					if(x==root)pos=i;
				}
			}
			for(int i=1;i<=n;i++)
				if(i!=root&&in[i]==INF)
					return -1;
			int cnt=0;
			for(int i=1;i<=n;i++)
				vis[i]=id[i]=0;
			for(int i=1;i<=n;i++){
				if(i==root)continue;
				ans+=in[i];
				int v=i;
				while(vis[v]!=i&&!id[v]&&v!=root){
					vis[v]=i;v=pre[v];
				}
				if(!id[v]&&v!=root){
					id[v]=++cnt;
					for(int u=pre[v];u!=v;u=pre[u])
						id[u]=cnt;
				}
			}
			if(cnt==0)break;
			for(int i=1;i<=n;i++)
				if(!id[i])id[i]=++cnt;
			in[root] = 0;
			for(int i=1;i<=m;i++){
				auto [u,v,w]=p[i];
				p[i].x=id[u];
				p[i].y=id[v];
				if(id[u]!=id[v])
					p[i].w-=in[v];
			}
			root=id[root];
			n=cnt;
		}
		return ans;
	}
	int get_rt(){
		return pos;
	}
}edm;

void solve()
{
	int n,m;
	while(cin>>n>>m)
	{
		edm.init(n+1);
		int sum=0;
		for(int i=1;i<=m;i++){
			int x,y,w;
			cin>>x>>y>>w;
			edm.add(x+1,y+1,w);
			sum+=w;
		}
		sum++;
		for(int i=1;i<=n;i++)
			edm.add(n+1,i,sum);
		int ans=edm.run(n+1);
		if(ans==-1||ans>=sum*2)cout<<"impossible\n\n";
		else cout<<ans-sum<<" "<<edm.get_rt()-1-m<<"\n\n";
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}