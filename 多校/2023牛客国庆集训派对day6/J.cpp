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
const int maxn=4e6+100;
struct node{
	int l,r,val,lazy;
}t[maxn];
vector<int>w[maxn];
int vis[maxn];
int id[maxn];
int to[maxn];
int v[maxn];
int p[maxn];
int n,m;
void clear(){
	t[1].lazy=1;
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		t[rt<<1].val=t[rt<<1|1].val=0;
		t[rt<<1].lazy=t[rt<<1|1].lazy=1;
		t[rt].lazy=0;
	}
}
void build(int rt,int l,int r){
	t[rt]={l,r,0,0};
	if(l==r)
		return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void update(int rt,int l){
	if(t[rt].l==t[rt].r){
		t[rt].val=1;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l);
	else update(rt<<1|1,l);
	pushup(rt);
}
int query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}
int query(int l,int r)
{
	int len=r-l+1;
	int sum=0;
	if(r>n)sum=query(1,l,n)+query(1,1,r-n);
	else sum=query(1,l,r);
	return len-sum;
}
int bound(int x,int k)
{
	if(x>n)x=1;
	if(n-t[1].val<k)k%=(n-t[1].val);
	if(k==0)k=n-t[1].val;
	int l=1,r=n,ans=1;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		int now=query(x,x+mid);
		if(now==k){
			ans=mid;break;
		}
		else if(now<k)l=mid+1;
		else r=mid-1;
	}
	while(query(x,ans)<k)ans++;
	while(query(x,ans)>k)ans--;

	if(ans>n)ans-=n;
	return ans;
}
void dfs(int x,int _id,int _tot)
{
	w[_tot].push_back(x);
	vis[x]=_tot;
	id[x]=_id;
	int y=v[x];
	if(vis[y])return ;
	dfs(y,_id+1,_tot);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		p[i]=i;
	build(1,1,n);
	while(m--)
	{
		clear();
		int k,x;cin>>k>>x;
		
		to[1]=k;update(1,k);
		v[k]=1;vis[1]=0;
		
		for(int i=2;i<=n;i++){
			to[i]=bound(to[i-1]+1,k);
			update(1,to[i]);
			v[to[i]]=i;
			vis[i]=0;
		}
		// for(int i=1;i<=n;i++)
		// 	cout<<to[i]<<" \n"[i==n];
		// for(int i=1;i<=n;i++)
		// 	cout<<v[i]<<" \n"[i==n];
		int tot=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])continue;
			tot++;
			w[tot].clear();
			dfs(i,0,tot);
		}
		// for(int i=1;i<=n;i++)
		// 	cout<<"i:"<<i<<" vis:"<<vis[i]<<" id:"<<id[i]<<endl;
		// cout<<"tot "<<tot<<endl;
		// for(int i=1;i<=tot;i++)
		// {
		// 	cout<<"tot:"<<i<<" \n";
		// 	for(auto j:w[i])
		// 		cout<<j<<" ";cout<<endl;
		// }
		for(int i=1;i<=n;i++)
		{
			int len=w[vis[i]].size();
			int now=w[vis[i]][ (id[i]+x)%len  ];
			to[now]=p[i];
		}
		// cout<<"end\n";
		for(int i=1;i<=n;i++)
		{
			p[i]=to[i];	
			// cout<<p[i]<<" ";
		}
		// cout<<endl;
	}
	// cout<<"end\n";
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" \n"[i==n];
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}