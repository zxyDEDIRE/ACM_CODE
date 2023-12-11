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
struct node{
	int l,r,val,sum,lazy,lazy_1,t;
}t[maxn<<2];
int n,q,ans;
void build(int rt,int l,int r)
{
	t[rt]={l,r,0,0,0,0,0};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushup(int rt,int ti)
{
	// int ti=max(t[rt<<1].t,t[rt<<1|1].t);
	if(t[rt<<1].t!=ti)
	{
		(t[rt<<1].sum+=t[rt<<1].val*(ti-t[rt<<1].t)%mod)%=mod;
		(t[rt<<1].lazy+=t[rt<<1].lazy_1*(ti-t[rt<<1].t)%mod)%=mod;
		t[rt<<1].t=ti;
	}
	if(t[rt<<1|1].t!=ti)
	{
		(t[rt<<1|1].sum+=t[rt<<1|1].val*(ti-t[rt<<1|1].t)%mod)%=mod;
		(t[rt<<1|1].lazy+=t[rt<<1|1].lazy_1*(ti-t[rt<<1|1].t)%mod)%=mod;
		t[rt<<1|1].t=ti;
	}
	(t[rt].sum=t[rt<<1].sum+t[rt<<1|1].sum)%=mod;
	(t[rt].val=t[rt<<1].val+t[rt<<1|1].val)%=mod;
	t[rt].t=ti;
	// cout<<t[rt<<1].sum<<" "<<t[rt<<1|1].sum<<endl;
	// cout<<"pushup "<<t[rt].l<<" "<<t[rt].r<<" "<<t[rt].sum<<endl;
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		(t[rt<<1].sum+=t[rt<<1].val*(t[rt].t-t[rt<<1].t)%mod+t[rt].lazy*(t[rt<<1].r-t[rt<<1].l+1)%mod)%=mod;
		(t[rt<<1].val+=t[rt].lazy_1*(t[rt<<1].r-t[rt<<1].l+1)%mod)%=mod;
		(t[rt<<1].lazy_1+=t[rt].lazy_1)%=mod;
		(t[rt<<1].lazy+=t[rt].lazy)%=mod;
		t[rt<<1].t=t[rt].t;

		(t[rt<<1|1].sum+=t[rt<<1|1].val*(t[rt].t-t[rt<<1|1].t)%mod+t[rt].lazy*(t[rt<<1|1].r-t[rt<<1|1].l+1)%mod)%=mod;
		(t[rt<<1|1].val+=t[rt].lazy_1*(t[rt<<1|1].r-t[rt<<1|1].l+1)%mod)%=mod;
		(t[rt<<1|1].lazy_1+=t[rt].lazy_1)%=mod;
		(t[rt<<1|1].lazy+=t[rt].lazy)%=mod;
		t[rt<<1|1].t=t[rt].t;

		// cout<<"down "<<t[rt].l<<" "<<t[rt].r<<" "<<t[rt].lazy<<" "<<t[rt<<1|1].sum<<endl;
		t[rt].lazy=0;
		t[rt].lazy_1=0;
	}
	else
	{
		(t[rt<<1].sum+=t[rt<<1].val*(t[rt].t-t[rt<<1].t)%mod)%=mod;
		(t[rt<<1].lazy+=t[rt<<1].lazy_1*(t[rt].t-t[rt<<1].t)%mod)%=mod;
		t[rt<<1].t=t[rt].t;

		(t[rt<<1|1].sum+=t[rt<<1|1].val*(t[rt].t-t[rt<<1|1].t)%mod)%=mod;
		(t[rt<<1|1].lazy+=t[rt<<1|1].lazy_1*(t[rt].t-t[rt<<1|1].t)%mod)%=mod;
		t[rt<<1|1].t=t[rt].t;
		// cout<<"else"<<" "<<t[rt].t<<" "<<t[rt].l<<" "<<t[rt].r<<endl;
	}
}
void update(int rt,int l,int r,int w,int ti)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		(t[rt].lazy+=t[rt].lazy_1*(ti-t[rt].t)%mod)%=mod;
		(t[rt].sum+=t[rt].val*(ti-t[rt].t)%mod)%=mod;
		(t[rt].sum+=w*(t[rt].r-t[rt].l+1)%mod)%=mod;
		(t[rt].val+=(t[rt].r-t[rt].l+1)*w%mod)%=mod;
		(t[rt].lazy+=w*(ti-t[rt].t)%mod)%=mod;
		(t[rt].lazy_1+=w)%=mod;
		t[rt].t=ti;


		// (t[rt].lazy+=t[rt].lazy_1*(ti-t[rt].t)%mod)%=mod;
		// (t[rt].val+=(t[rt].r-t[rt].l+1)*w%mod)%=mod;
		// (t[rt].sum+=t[rt].val*(ti-t[rt].t)%mod)%=mod;
		// (t[rt].lazy+=w*(ti-t[rt].t)%mod)%=mod;
		// (t[rt].lazy_1+=w)%=mod;
		// t[rt].t=ti;

		// cout<<"TR "<<t[rt].l<<" "<<t[rt].r<<" "<<t[rt].sum<<" "<<ti<<endl;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,w,ti);
	if(r>mid)update(rt<<1|1,l,r,w,ti);
	pushup(rt,ti);
}
void query(int rt,int l,int r,int ti)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{	
		// cout<<"query "<<t[rt].sum<<" "<<t[rt].val<<" "<<t[rt].t<<endl;
		(t[rt].sum+=t[rt].val*(ti-t[rt].t)%mod)%=mod;
		t[rt].t=ti;
		(ans+=t[rt].sum)%=mod;
		// cout<<"query "<<t[rt].sum<<endl;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)query(rt<<1,l,r,ti);
	if(r>mid)query(rt<<1|1,l,r,ti);
	pushup(rt,ti);
}
void solve()
{
	cin>>n>>q;
	build(1,1,n);
	for(int i=1;i<=q;i++)
	{
		int op,x,y,w;
		cin>>op>>x>>y;
		if(op==0)
		{
			cin>>w;
			update(1,x,y,w,i);
		}
		else
		{
			ans=0;
			query(1,x,y,i);
			cout<<ans<<endl;
		}
		// cout<<"ans "<<t[1].sum<<" "<<t[1].t<<endl;
	}
}
signed main(){
	// freopen("C:\\Users\\tob\\Desktop\\in.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
6 3
0 1 6 3
0 6 6 5
1 3 3

3 3 3 3 3 3 
3 3 3 3 3 8
3 3 3 3 3 8

9 9 9 9 9 19


45+19=64
*/