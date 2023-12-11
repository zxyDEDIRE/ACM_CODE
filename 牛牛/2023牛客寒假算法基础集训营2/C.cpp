/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int l,r,lazy,val;
}t[maxn<<2];
pii p[maxn];
int n,m;
void build(int rt,int l,int r)
{
	t[rt]={l,r,0,0};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushup(int rt){
	t[rt].val=(t[rt<<1].val+t[rt<<1|1].val)%mod;
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		int m=(t[rt].l+t[rt].r)>>1;
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1|1].lazy+=t[rt].lazy;

		t[rt<<1].val+=(m-t[rt].l+1)*t[rt].lazy;
		t[rt<<1|1].val+=(t[rt].r-m)*t[rt].lazy;

		t[rt].lazy=0;
	}
}
void update(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r){
		t[rt].val=(t[rt].val+(k*(t[rt].r-t[rt].l+1))%mod)%mod;
		t[rt].lazy=(t[rt].lazy+k)%mod;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt].val;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans=(ans+query(rt<<1,l,r))%mod;
	if(r>mid)ans=(ans+query(rt<<1|1,l,r))%mod;
	return ans%mod;
}
void solve()
{
	cin>>n>>m;
	build(1,0,4e5+7);
	for(int i=1;i<=m;i++)
	{
		cin>>p[i].first>>p[i].second;
		update(1,p[i].first,p[i].second,1);
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		update(1,p[i].first,p[i].second,-1);
		// cout<<ans<<" ";
		ans=(ans+query(1,max(0,n-p[i].second),max(0,n-p[i].first)))%mod;
		// cout<<ans<<endl;
		update(1,p[i].first,p[i].second,1);
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
2 3
1 2
2 3
3 4
*/