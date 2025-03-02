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
	int l,r,val,lazy;
}t[maxn];
string str;
int n;
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void f(int rt)
{
	t[rt].lazy^=1;
	t[rt].val=(t[rt].r-t[rt].l+1)-t[rt].val;
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		f(rt<<1);
		f(rt<<1|1);
		t[rt].lazy=0;
	}
}
void build(int rt,int l,int r)
{
	t[rt]={l,r,0,0};
	if(l==r){
		t[rt].val=(str[l-1]=='1');
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		f(rt);
		return ;
	}
	pushup(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r);
	if(r>mid)update(rt<<1|1,l,r);
	pushup(rt);
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
void solve()
{
	cin>>n>>str;
	for(int len=n;len>1;len--)
	{
		build(1,1,n);
		for(int i=1;i+len<=n;i++)
		{
			if(query(1,i,i)==0){
				// cout<<i<<endl;
				update(1,i,i+len-1);
			}
		}
		// cout<<n-len+1<<" "<<n<<" "<<query(1,n-len+1,n)<<endl;
		int ans=query(1,n-len+1,n);
		if(ans==len||ans==0)
		{
			cout<<len<<endl;
			return ;
		}
	}
	cout<<1<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
1011101
1100101
1111001

1011101
1100001
1111111
*/