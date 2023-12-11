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
	int l,r,val;
}t[maxn<<2];
int p[maxn];
int n,q;
void pushup(int rt){
	t[rt].val=(t[rt<<1].val|t[rt<<1|1].val);
}
void build(int rt,int l,int r){
	t[rt]={l,r,0};
	if(l==r){
		t[rt].val=p[l];
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
	int ans=0;
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)ans|=query(rt<<1,l,r);
	if(r>mid)ans|=query(rt<<1|1,l,r);
	return ans;
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	build(1,1,n);
	while(q--)
	{
		int l,r,x;
		cin>>l>>r>>x;
		cout<<(query(1,l,r)|x)<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}