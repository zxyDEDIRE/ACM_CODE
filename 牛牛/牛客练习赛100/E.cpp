#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cout.tie(0);cout.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=20011;
const int mod=1e9+7;
struct node{
	int l,r;
	int a[2964];
	int lazy;
}t[maxn<<2];
bool vis[maxn];
int prime[maxn];
int p[maxn];
int qu[2964];
int n,q,cnt;
void init()
{
	prime[0]=0;
	for(int i=2;i<=maxn;i++)
	{
		if(!vis[i])prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&prime[j]*i<=maxn;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		} 
	}
}
void pushup(int rt)
{
	for(int i=1;i<=cnt;i++)
		t[rt].a[i]=max(t[rt<<1].a[i],t[rt<<1|1].a[i]);
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].lazy=0;
	if(l==r){
		int x=p[l];
		for(int i=1;i<=cnt;i++)
		{
			t[rt].a[i]=0;
			while(x%prime[i]==0){
				t[rt].a[i]++;
				if(prime[i]!=0)
				x/=prime[i];
			}
		}
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);

	pushup(rt);
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		for(int i=1;i<=cnt;i++){
			t[rt<<1].a[i]=t[rt<<1|1].a[i]=t[rt].a[i];
		}
		t[rt<<1].lazy=t[rt<<1|1].lazy=1;
		t[rt].lazy=0;
	}
}
void query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		for(int i=1;i<=cnt;i++)
			qu[i]=max(qu[i],t[rt].a[i]);
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)query(rt<<1,l,r);
	if(r>mid)query(rt<<1|1,l,r);
	pushup(rt);
}
void update(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		for(int i=1;i<=cnt;i++)
			t[rt].a[i]=qu[i];
		t[rt].lazy=1;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r);
	if(r>mid)update(rt<<1|1,l,r);
	pushup(rt);
}
signed main()
{	ios
	init();
	cnt=prime[0];
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	build(1,1,n);
	while(q--)
	{
		int x,y;
		cin>>x>>y;

		for(int i=1;i<=cnt;i++)
			qu[i]=0;
		
		query(1,x,y);
		update(1,x,y);

		ll ans=1;
		for(int i=1;i<=cnt;i++)
		{
			for(int j=1;j<=qu[i];j++)
				ans=(ans*prime[i])%mod;
		}
		cout<<ans<<"\n";
	}
}