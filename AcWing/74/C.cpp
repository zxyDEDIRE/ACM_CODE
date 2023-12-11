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
struct Seg{
	int l,r,val;
}t[maxn<<2];
int a[maxn],b[maxn];
int T[maxn];
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
void update(int rt,int l){
	if(t[rt].l==t[rt].r){
		t[rt].val++;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l);
	else update(rt<<1|1,l);
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i],T[i]=p[i];
	sort(T+1,T+1+n);
	m=unique(T+1,T+1+n)-T-1;
	for(int i=1;i<=n;i++)
		p[i]=lower_bound(T+1,T+1+m,p[i])-T;
	build(1,1,m);
	for(int i=1;i<=n;i++)
	{
		a[i]=query(1,p[i]+1,m);
		update(1,p[i]);
	}
	build(1,1,m);
	for(int i=n;i>=1;i--)
	{
		b[i]=query(1,1,p[i]-1);
		update(1,p[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=a[i]*b[i];
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