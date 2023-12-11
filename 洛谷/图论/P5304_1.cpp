#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,ll>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const ll INF=1e18+7;
const int maxn=1e6+100;
struct Node{
	int id;ll dis;
	bool operator<(const Node&a)const{
		return a.dis<dis;
	}
};
vector<pii>v[maxn];
vector<int>p;
bool vis[maxn];
ll dis[maxn];
ll res;
int n,m,k;
void init(){
	for(int i=1;i<=n+2;i++)
		v[i].clear();
	res=INF;
	p.clear();
}
void dij(vector<int>&pa,vector<int>&pb)
{
	priority_queue<Node>q;
	for(int i=1;i<=n;i++)dis[i]=INF,vis[i]=0;
	for(auto x:pa)
		q.push({x,0ll}),dis[x]=0;
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto [y,w]:v[x])
		{
			if(dis[y]>dis[x]+w)
			{
				dis[y]=dis[x]+w;
				q.push({y,dis[y]});
			}
		}
	}
	for(auto x:pb)
		res=min(res,dis[x]);
}
void f(ll _x)
{
	vector<int>pa,pb;
	for(auto x:p){
		if(x&_x)pa.push_back(x);
		else pb.push_back(x);
	}
	if(pa.size()==0||pb.size()==0)return ;
	dij(pa,pb);
	dij(pb,pa);
}
void solve()
{
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		v[x].push_back({y,w});
	}
	for(int i=1;i<=k;i++){
		int x;cin>>x;
		p.push_back(x);
	}
	sort(p.begin(),p.end());
	for(int i=0;i<=20;i++){
		f(1ll<<i);
	}
	cout<<res<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*

6 7 3
1 5 3
2 3 5
1 4 3
5 3 2
4 6 5
4 3 7
5 6 4
1 3 6

*/