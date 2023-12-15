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
struct node{
	int l,r,val;
}t[maxn<<2];
ll p[maxn];
int n,m;
void pushup(int rt){
	t[rt].val=min(t[rt<<1].val,t[rt<<1|1].val);
}
void build(int rt,int l,int r){
	t[rt].l=l;
	t[rt].r=r;
	if(l==r){
		cin>>p[l];
		if(p[l]>0)t[rt].val=l;
		else if(p[l]==0)t[rt].val=n+1;
		else t[rt].val=INF;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int k){
	if(t[rt].l==t[rt].r){
		t[rt].val=k;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,k);
	else update(rt<<1|1,l,k);
	pushup(rt);
}
int query(int rt,int l,int r){
	// cout<<t[rt].l<<" "<<t[rt].r<<endl;
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt].val;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=INF;
	if(l<=mid)ans=min(ans,query(rt<<1,l,r));
	if(r>mid)ans=min(ans,query(rt<<1|1,l,r));
	return ans;
}
ll mull(ll a,ll b){ll qw=0;while(b){if(b&1)qw=(qw+a)%mod;a=(a+a)%mod;b>>=1;}return qw;}
ll ksm(ll b,ll p){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
ll ksm(ll b,ll p,ll mod){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}

ll f(int l,int r)
{
	// cout<<l<<" "<<r<<endl;
	int pos=query(1,l,r);
	if(pos==n+1)return 0;
	else if(pos==INF)
	{
		__int128 ma=0,t=1,fa=-1;
		for(int i=max(l,r-50),j=1;i<=r;i++,j++)
		{
			__int128 now=(t<<j)*p[i];
			// cout<<"I "<<i<<" "<<(ll)now<<endl;
			if(fa==-1){
				ma=now;
				fa=i;
			}
			if(now>ma)
			{
				ma=now;
				fa=i;
			}
		}
		// cout<<"Fa "<<(ll)fa<<endl;
		return mull((p[fa]%mod+mod),ksm(2,r-fa));
	}
	else
	{
		__int128 ma=0,t=1,fa=pos;
		for(int i=pos,j=1;i<=min(pos+50,r);i++,j++)
		{
			__int128 now=(t<<j)*p[i];
			if(now>ma)
			{
				ma=now;
				fa=i;
			}
		}
		return mull(p[fa],ksm(2,r-fa+1));
	}
}
void solve()
{
	cin>>n>>m;
	build(1,1,n);
	while(m--)
	{
		int op,x,w,l,r;
		cin>>op;
		if(op==1)
		{
			cin>>x>>w;
			if(p[x]!=0&&p[x]+w==0)update(1,x,n+1);
			if(p[x]<=0&&p[x]+w>0)update(1,x,x);
			if(p[x]>=0&&p[x]+w<0)update(1,x,INF);
			p[x]+=w;
		}
		else
		{
			cin>>l>>r;
			cout<<f(l,r)<<endl;
		}
	}
	// for(int i=1;i<=n;i++)
	// 	cout<<p[i]<<" ";cout<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
4 4
1 2 3 8
  4
    8 
     16
*/