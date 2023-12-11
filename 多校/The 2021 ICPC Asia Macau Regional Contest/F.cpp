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
struct Seg{
	int l,r,v1,v2,lazy;
}t[maxn<<2];
int p[maxn];
int flag=0;
int n;
void pushup(int rt)
{
	if(t[rt<<1].v1>=t[rt<<1|1].v1)
	{
		t[rt].v1=t[rt<<1].v1;
		t[rt].v2=t[rt<<1].v2;	
	}
	else
	{
		t[rt].v1=t[rt<<1|1].v1;
		t[rt].v2=t[rt<<1|1].v2;	
	}
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		t[rt<<1].v1+=t[rt].lazy;
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1|1].v1+=t[rt].lazy;
		t[rt<<1|1].lazy+=t[rt].lazy;
		t[rt].lazy=0;
	}
}
void build(int rt,int l,int r)
{
	t[rt]={l,r,0,0,0};
	if(l==r){
		t[rt].v1=p[l];
		if(!t[rt].v1)flag=1;
		t[rt].v2=l;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].v1+=k;
		t[rt].lazy+=k;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
bool f()
{
	int x=t[1].v1;
	int y=t[1].v2;
	if(x<n-1)return 1;
	update(1,1,n,1);
	update(1,y,y,-n);
	return 0;
}
void dfs(int rt)
{
	pushdown(rt);
	if(t[rt].l==t[rt].r){
		p[t[rt].l]=t[rt].v1;
		return ;
	}
	dfs(rt<<1);
	dfs(rt<<1|1);
}
void get()
{
	dfs(1);
}
void solve()
{
	cin>>n;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(!p[i])flag=1;
	}
	build(1,1,n);
	for(int i=1;i<=n+1;i++)
	{
		int now=f();
		if(now==1)
		{
			get();
			for(int j=1;j<=n;j++){
				cout<<p[j];
				if(j!=n)cout<<" ";
			}
			return ;
		}
	}
	cout<<"Recurrent";
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}