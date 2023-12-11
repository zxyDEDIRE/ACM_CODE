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
const int maxn=1e6+100;
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
	cin>>n>>m;
	edm.init(n);
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		edm.add(x+1,y+1,w);
	}
	int ans=edm.run(1);
	if(ans==-1)cout<<"Possums!\n";
	else cout<<ans<<"\n";
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	for(int i=1;i<=__;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}