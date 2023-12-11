/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
	int l,r,val;
}t[maxn<<2];
int a[maxn];
int p[maxn];
int n,m;
void build(int rt,int l,int r)
{
	t[rt]={l,r,0};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushup(int rt)
{
	t[rt].val=max(t[rt<<1].val,t[rt<<1|1].val);
}
void update(int rt,int l,int k)
{
	if(t[rt].l==t[rt].r)
	{
		t[rt].val=max(t[rt].val,k);
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,k);
	else update(rt<<1|1,l,k);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(r<l)return 0;
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans=max(ans,query(rt<<1,l,r));
	if(r>mid)ans=max(ans,query(rt<<1|1,l,r));
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i],a[i]=p[i];
	sort(a+1,a+1+n);
	m=unique(a+1,a+1+n)-a-1;
	build(1,1,n);
	int ma=0;
	for(int i=1;i<=n;i++)
	{
		int fl=lower_bound(a+1,a+1+m,p[i])-a;
		int ans=query(1,1,fl-1);
		ans+=p[i];
		update(1,fl,ans);
		ma=max(ma,ans);
	}
	cout<<ma<<endl;
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