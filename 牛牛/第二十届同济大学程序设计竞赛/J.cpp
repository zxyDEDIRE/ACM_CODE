/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
struct Seg{
	int l,r,val,lazy_1,lazy_2;
}t[maxn<<2];
vector<int>v[maxn];
bitset<maxn>vis;
int id[maxn],di[maxn],tot;
int L[maxn],R[maxn];
int dep[maxn];
int f[maxn][23];
int p[maxn];
int n,q,ma_dep;
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void pushdown(int rt)
{
	if(t[rt].lazy_2)
	{
		t[rt<<1].val=t[rt<<1|1].val=t[rt<<1].lazy_2=t[rt<<1|1].lazy_2=t[rt].lazy_2;
		t[rt<<1].lazy_1=t[rt<<1|1].lazy_1=0;
		t[rt].lazy_2=0;
	}
	else if(t[rt].lazy_1)
	{
		t[rt<<1].val+=t[rt].lazy_1*(t[rt<<1].r-t[rt<<1].l+1);
		t[rt<<1|1].val+=t[rt].lazy_1*(t[rt<<1|1].r-t[rt<<1|1].l+1);
		t[rt<<1].lazy_1+=t[rt].lazy_1;
		t[rt<<1|1].lazy_1+=t[rt].lazy_1;
		t[rt].lazy_1=0;
	}
}
void build(int rt,int l,int r)
{
	t[rt]={l,r,0,0,0};
	if(t[rt].l==t[rt].r){
		t[rt].val=p[di[l]];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int op,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r){
		if(op==1){
			t[rt].val=k;
			t[rt].lazy_2=k;
			t[rt].lazy_1=0;
		}
		else {
			t[rt].val+=k*(t[rt].r-t[rt].l+1);
			t[rt].lazy_1+=k;
		}
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,op,k);
	if(r>mid)update(rt<<1|1,l,r,op,k);
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}
void bfs()
{
	queue<int>q;
	q.push(1);
	vis[1]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		id[x]=++tot;
		di[tot]=x;
		ma_dep=max(ma_dep,dep[x]);
		L[dep[x]]=min(L[dep[x]],id[x]);
		R[dep[x]]=max(R[dep[x]],id[x]);
		for(auto y:v[x])
		{
			if(vis[y])continue;
			dep[y]=dep[x]+1;
			vis[y]=1;
			q.push(y);
		}
	}
}
void dfs(int x,int fa)
{
	f[id[x]][0]=id[fa];
	for(int i=1;i<=20;i++)
		f[id[x]][i]=f[f[id[x]][i-1]][i-1];
	for(auto y:v[x])
		if(y!=fa)
			dfs(y,x);
}
pii Q(int d,int x)
{
	int l,r,ans_l,ans_r;
	l=L[d],r=R[d],ans_l=l;

	auto check_1=[&](int mid)->bool{
		int now=d-dep[mid];
		int y=id[mid];
		for(int i=20;i>=0;i--)
			if(now>=(1<<i)){
				now-=(1<<i);
				y=f[y][i];
			}
		return y>=id[x];
	};

	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check_1(mid))ans_l=mid,r=mid;
		else l=mid;
	}
	while(ans_l>L[d]&&check_1(ans_l-1))ans_l--;


	auto check_2=[&](int mid)->bool{
		int now=d-dep[mid];
		int y=id[mid];
		for(int i=20;i>=0;i--)
			if(now>=(1<<i)){
				now-=(1<<i);
				y=f[y][i];
			}
		return y<=id[x];
	};


	l=L[d],r=R[d],ans_r=r;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check_2(mid))ans_r=mid,l=mid;
		else r=mid;
	}
	while(ans_r<R[d] && check_2(ans_r+1))ans_r++;
	return {ans_l,ans_r};
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		L[i]=n;
		R[i]=1;
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs();
	dfs(1,0);
	build(1,1,n);
	cin>>q;
	while(q--)
	{
		int op,x,y,k;
		cin>>op;
		if(op==1)
		{
			cin>>x>>k;
			x=id[x];
			update(1,id[x],id[x],1,k);
		}
		else if(op==2)
		{
			cin>>x>>y>>k;
			auto t=Q(dep[x]+y,x);
			update(1,t.first,t.second,1,k);
		}
		else if(op==3)
		{
			cin>>x>>y>>k;
			auto t=Q(dep[x]+y,x);
			update(1,t.first,t.second,2,k);
		}
		else if(op==4)
		{
			cin>>x;
			cout<<query(1,id[x],id[x])<<endl;
		}
		else if(op==5)
		{
			cin>>x>>y;
			if(dep[x]+y>ma_dep){
				cout<<0<<endl;
				continue;
			}
			auto t=Q(dep[x]+y,x);
			cout<<query(1,t.first,t.second)<<endl;
		}
	}
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