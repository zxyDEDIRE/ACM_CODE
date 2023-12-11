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
const ll INF=1e16+7;
const int maxn=1e6+100;


struct Seg{
	int l,r;ll val,lazy;
}t[maxn<<2];
void pushup(int rt){
	t[rt].val=min(t[rt<<1].val,t[rt<<1|1].val);
};
void pushdown(int rt){
	if(t[rt].lazy!=INF)
	{
		t[rt<<1].val=min(t[rt<<1].val,t[rt].lazy);
		t[rt<<1|1].val=min(t[rt<<1|1].val,t[rt].lazy);
		t[rt<<1].lazy=min(t[rt<<1].lazy,t[rt].lazy);
		t[rt<<1|1].lazy=min(t[rt<<1|1].lazy,t[rt].lazy);
		t[rt].lazy=INF;
	}
};
void build(int rt,int l,int r){
	t[rt]={l,r,INF,INF};
	if(l==r){
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void update(int rt,int l,int r,ll k){
	if(l<=t[rt].l&&t[rt].r<=r){
		t[rt].val=min(t[rt].val,k);
		t[rt].lazy=min(t[rt].lazy,k);
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
ll query(int rt,int l){
	if(t[rt].l==t[rt].r){
		return t[rt].val;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)return query(rt<<1,l);
	else return query(rt<<1|1,l);
}


struct node{
	int id;ll dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct ano1_node{
	int x,id;
	bool operator<(const ano1_node&a)const{
		return a.id<id;
	}
};
struct ano2_node{
	int x,id;
	bool operator<(const ano2_node&a)const{
		return a.id>id;
	}
};
pp(3) edge[maxn];
vector<pp(3)>v[maxn];
vector<pii>p;
bitset<maxn>vis,is;
pii pre[maxn];
pii suf[maxn];
ll dis1[maxn];
ll dis2[maxn];
int _id[maxn];
int id[maxn];
int L[maxn];
int R[maxn];
int n,m,q;
void dij(int s,int t,ll* dis,int op)
{
	for(int i=1;i<=n;i++)
		dis[i]=INF,vis[i]=0;
	priority_queue<node>q;
	q.push({s,0ll});
	dis[s]=0;
	while(!q.empty()){
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto [y,w,id]:v[x]){
			if(dis[y]>dis[x]+w){
				if(op)pre[y]={x,id};
				else suf[y]={x,id};
				dis[y]=dis[x]+w;
				q.push({y,dis[y]});
			}
		}
	}
}
void solve()
{
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		v[x].push_back({y,w,i});
		v[y].push_back({x,w,i});
		edge[i]={x,y,w};
	}
	dij(1,n,dis1,1);
	dij(n,1,dis2,0);

	int now=1;
	while(now!=n)
	{
		is[suf[now].second]=1;
		p.push_back({now,suf[now].second});
		now=suf[now].first;
	}p.push_back({n,0});
	
	int len=p.size();
	for(int i=0;i<len;i++)
	{
		auto [x,y]=p[i];
		_id[x]=i;
		L[x]=x;
		R[x]=x;
	}
	
	for(int i=0;i<len-1;i++)
		id[p[i].second]=i+1;

	vis.reset();
	priority_queue<ano1_node>q1;
	q1.push({1,_id[1]});
	while(!q1.empty())
	{
		auto [x,ID]=q1.top();q1.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto [y,w,id]:v[x])
			if(dis1[y]==dis1[x]+w){
				if(!L[y])L[y]=L[x];
				q1.push({y,_id[L[y]]});
			}
	}
	vis.reset();
	priority_queue<ano2_node>q2;
	q2.push({n,_id[n]});
	while(!q2.empty())
	{
		auto [x,ID]=q2.top();q2.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto [y,w,id]:v[x])
			if(dis2[y]==dis2[x]+w){
				if(!R[y])R[y]=R[x];
				q2.push({y,_id[R[y]]});
			}
	}

	build(1,1,len-1);
	for(int i=1;i<=m;i++)
	{
		if(is[i])continue;
		auto [x,y,w]=edge[i];
		if(!L[x]||!L[y])continue;
		ll d,l,r;

		d=dis1[x]+dis2[y]+w;
		l=L[x],r=R[y];
		if(_id[l]+1<=_id[r])update(1,_id[l]+1,_id[r],d);

		swap(x,y);

		d=dis1[x]+dis2[y]+w;
		l=L[x],r=R[y];
		if(_id[l]+1<=_id[r]) update(1,_id[l]+1,_id[r],d);
	}
	while(q--)
	{
		int op,c;
		cin>>op>>c;
		auto [x,y,w]=edge[op];
		ll ans;
		if(is[op])
		{
			if(c<=w) ans=dis1[n]-w+c;
			else ans=min(dis1[n]-w+c,query(1,id[op]));
		}
		else
		{
			if(c>=w) ans=dis1[n];
			else ans=min({dis1[n], dis1[x]+c+dis2[y], dis1[y]+c+dis2[x]});
		}
		cout<<ans<<endl;
	}
}
signed main(){
 // freopen("b.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}