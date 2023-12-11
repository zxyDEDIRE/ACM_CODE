/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
const int maxn=1e5+100;
vector<vector<pii>>v;
vector<int>c,p;
class Seg_1{
public:
	struct node{
		int l,r,val;
	};
	vector<node>t;
	vector<int>dis;
	int n;
	Seg_1(int x):n(x){
		cout<<"Sseg_1"<<endl;
		t.resize(n*4+1);
		dis.resize(n+1);
	}
	void init()
	{
		queue<int>q;
		for(int i=1;i<=n;i++)
			dis[i]=INF;
		for(auto y:p)
			dis[y]=0,q.push(y);
		while(!q.empty())
		{
			int x=q.front();q.pop();
			for(auto [y,w]:v[x])
				if(dis[y]>dis[x]+1){
					dis[y]=dis[x]+1;
					q.push(y);
				}
		}
		build(1,1,n);
	}
	void pushup(int rt){
		t[rt].val=min(t[rt<<1].val,t[rt<<1|1].val);
	}
	void build(int rt,int l,int r){
		t[rt]={l,r,0};
		if(l==r){
			t[rt].val=dis[l];
			return ;
		}
		int mid=(l+r)>>1;
		build(rt<<1,l,mid);
		build(rt<<1|1,mid+1,r);
		pushup(rt);
	}
	int query(int rt,int l,int r){
		if(l<=t[rt].l&&t[rt].r<=r)
			return t[rt].val;
		int mid=(t[rt].l+t[rt].r)>>1;
		int ans=INF;
		if(l<=mid)ans=min(ans,query(rt<<1,l,r));
		if(r>mid)ans=min(ans,query(rt<<1|1,l,r));
		return ans;
	}
};
class Seg_2{
public:
	struct node{
		int l,r,val;
	};
	vector<node>t;
	int n;
	Seg_2(int x):n(x){
		t.resize(n*4+1);
	}
	void init()
	{
		build(1,1,n);
	}
	void pushup(int rt){
		t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
	}
	void build(int rt,int l,int r){
		t[rt]={l,r,0};
		if(l==r){
			t[rt].val=c[l];
			return ;
		}
		int mid=(l+r)>>1;
		build(rt<<1,l,mid);
		build(rt<<1|1,mid+1,r);
		pushup(rt);
	}
	int query(int rt,int l,int r){
		if(l<=t[rt].l&&t[rt].r<=r){
			return t[rt].val;
		}
		int mid=(t[rt].l+t[rt].r)>>1;
		int ans=0;
		if(l<=mid)ans+=query(rt<<1,l,r);
		if(r>mid)ans+=query(rt<<1|1,l,r);
		return ans;
	}
};
class Qtree{
public:
	vector<int>f,son,dep,siz,top,id,di;
	Seg_1 s1;
	Seg_2 s2;
	int n,tot;
	Qtree(int x):n(x),s1(n),s2(n){
		v.resize(n+1);f.resize(n+1);
		son.resize(n+1);dep.resize(n+1);
		siz.resize(n+1);top.resize(n+1);
		id.resize(n+1);di.resize(n+1);
		c.resize(n+1);
		tot=0;
		cout<<v.size()<<endl;
	}
	void add(int x,int y,int w){
		v[x].push_back({y,w});
		v[y].push_back({x,w});
	}
	void init()
	{
		dfs1(1,0);
		dfs2(1,1);
		s1.init();
		s2.init();
	}
	void dfs1(int x,int fa){
		dep[x]=dep[fa]+1;
		siz[x]=1;
		f[x]=fa;
		son[x]=0;
		for(auto [y,w]:v[x])
		{
			if(y==fa)continue;
			dfs1(y,x);
			c[y]=w;
			siz[x]+=siz[y];
			if(siz[y]>siz[son[x]])
				son[x]=y;
		}
	}
	void dfs2(int x,int topf){
		top[x]=topf;
		id[x]=++tot;
		di[tot]=x;
		if(son[x])dfs2(son[x],topf);
		for(auto [y,w]:v[x])
		{
			if(y==son[x]||y==f[x])continue;
			dfs2(y,y);
		}
	}
	int qRange(int x,int y)
	{
		int mi=INF;
		int sum=0;
		while(top[x]!=top[y])
		{
			if(dep[x]<dep[y])swap(x,y);
			mi=min(mi,s1.query(1,id[top[x]],id[x]));
			sum+=s2.query(1,id[top[x]],id[x]);
			x=f[top[x]];
		}
		if(dep[x]>dep[y])swap(x,y);
		mi=min(mi,s1.query(1,id[top[x]],id[x]));
		sum+=s2.query(1,id[top[x]],id[x]);
		return mi+sum;
	}
	void query(int q)
	{
		while(q--)
		{
			int s,t;
			cin>>s>>t;
			cout<<qRange(s,t)<<endl;
		}
	}
};
int n,q,k;
void solve()
{
	cin>>n>>q>>k;
	Qtree t(n);
	// t.add(1,1,1);
	for(int i=1;i<n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		t.add(x,y,w);
	}
	// p.resize(k+1);
	// for(int i=0;i<k;i++)
	// 	cin>>p[i];
	// t.init();
	// t.query(q);

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