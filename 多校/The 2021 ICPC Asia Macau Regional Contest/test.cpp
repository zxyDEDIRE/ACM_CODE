/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
	int l,r,val;
}t[maxn<<2];
int a[maxn];
int w[maxn];
int ans[maxn];
int n,m;
void pushdown(int rt){
	t[rt<<1].val=max(t[rt<<1].val,t[rt].val);
	t[rt<<1|1].val=max(t[rt<<1|1].val,t[rt].val);
}
void build(int rt,int l,int r){
	t[rt]={l,r,0};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void update(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].val=max(t[rt].val,k);
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
}
void dfs(int rt)
{
	if(t[rt].l==t[rt].r)
	{
		ans[t[rt].l]=t[rt].val;
		return ;
	}
	pushdown(rt);
	dfs(rt<<1);
	dfs(rt<<1|1);
}
void solve()
{
	cin>>n>>m;
	for(int i=1,x;i<=n;i++)
	{
		cin>>a[i]>>x;
		w[a[i]]=max(w[a[i]],x);
	}
	sort(a+1,a+1+n);
	n=unique(a+1,a+1+n)-a-1;
	build(1,1,m);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j+=2ll*a[i])
		{
			update(1,j+1,min(m,j+a[i]),w[a[i]]);
		}
	}
	dfs(1);
	for(int i=1;i<=n;i++)
		w[a[i]]=0;
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i];
		if(i!=m)cout<<" ";
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __=1;
	cin>>__;
	for(int i=1;i<=__;i++){
		cout<<"Case #"<<i<<": ";
		solve();
		if(i!=__)cout<<endl;
	}
	return 0;
}
/*
2
1 3
6 10

1 5
6 1

*/