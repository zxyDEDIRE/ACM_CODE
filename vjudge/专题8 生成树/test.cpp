#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1010;
const int maxm = 10005;




class Edmonds{
public:
	struct Edge{
		int x, y, cost;
	}p[maxm];
	int pre[maxn], id[maxn], vis[maxn], in[maxn];
	int n,m,root,pos;
	Edmonds(){}
	void init(int _n){
		n=_n;m=0;
	}
	void add(int x,int y,int w){
		p[++m]={x,y,w};
	}
	int run(int _root)
	{
		root=_root;
		int ans = 0;
		while (1)
		{
			for(int i=1;i<=n;i++) 
				in[i] = INF;
			for(int i=1;i<=m;++i)
			{
				auto [x,y,w]=p[i];
				if(p[i].cost<in[y] && x!=y)
				{
					pre[y]=x;
					in[y]=w;
					if(x==root)pos = i;      // 标记最小根
				}
			}
			for (int i = 1; i <= n; i++)
			{
				if (i != root && in[i] == INF) return -1;
			}
			int tn = 0;
			for(int i=1;i<=n;i++)
				vis[i]=id[i]=0;
			in[root] = 0;
			for(int i = 1; i <= n; i++)
			{
				if(i==root)continue;
				ans += in[i];
				int y = i;
				while(vis[y]!=i && !id[y] && y != root)
				{
					vis[y] = i;
					y = pre[y];
				}
				if(y!=root && !id[y])
				{
					id[y] = ++tn;
					for(int x = pre[y]; x != y ; x = pre[x]) 
						id[x] = tn;
				}
			}
			if (tn == 0) break;
			for (int i = 1; i <= n; i++){
				if(!id[i]) id[i] = ++tn;
			}
			for (int i = 1; i <= m; i++){
				int y = p[i].y;
				p[i].x = id[p[i].x];
				p[i].y = id[p[i].y];
				if (p[i].x != p[i].y) p[i].cost -= in[y];
			}
			n = tn;
			root = id[root];
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
	while(cin>>n>>m){
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
		else cout<<ans-sum<<" "<<edm.get_rt()-m-1<<"\n\n";
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}