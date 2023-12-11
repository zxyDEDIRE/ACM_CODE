#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=__int128;
using pii=pair<ll,ll>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const ll INF=1e18+7;
const int maxn=1e6+100;
struct node{
	int l,r;
	pii val;
}t[maxn];
ll pre[maxn];
int b[maxn];
int n;
pii max(pii a,pii b)
{
	if(a.first==b.first)
	{
		if(a.second>b.second)return a;
		else return b;
	}
	else if(a.first>b.first)return a;
	else return b;
}
void pushup(int rt)
{
	t[rt].val=max(t[rt<<1].val,t[rt<<1|1].val);
}
void build(int rt,int l,int r)
{
	t[rt]={l,r,{-INF,0}};
	if(l==r){
		t[rt].val={pre[l],l};
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}

pii query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	pii ans={-INF,0};
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)ans=max(ans,query(rt<<1,l,r));
	if(r>mid)ans=max(ans,query(rt<<1|1,l,r));
	return ans;
}
inline void read(int &x){
   int s = 0, w = 1; char ch = getchar();
   while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar(); }
   while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
   x = s*w;
   return ;
}

inline void write(ll x){
    if(x<0){
    	putchar('-');
		x=-x;
	}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}  

void solve()
{
	read(n);
	b[0]=1e9;
	for(int i=1,x;i<=n;i++){
		read(x);
		pre[i]=pre[i-1]+x;
	}
	for(int i=1;i<=n;i++){
		// cin>>b[i];
		read(b[i]);
		b[i]=min(b[i],b[i-1]);
	}
	build(1,1,n);
	int l=1,r=n;
	ll ans=0;
	for(int t=1;t<=b[1];t++)
	{
		pii now=query(1,l,r);
		ans+=now.first;
		while(b[r]-t==0)r--;
	}
	write(b[1]);
	printf(" ");
	write(ans);
	printf("\n");
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;read(__);
	for(int i=1;i<=__;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
/*
*/