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
const int maxn=2e6+100;
struct node{
	int l,r,val;
}t[maxn<<2];
pii p[maxn];
int a[maxn];
int T[maxn];
int n,m,q;
void build(int rt,int l,int r)
{
	t[rt]={l,r,0};
	if(l==r){
		t[rt].val=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
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
bool check(int mid)
{
	for(int i=1;i<=n;i++)
		a[i]=0;
	for(int i=1;i<=mid;i++)
		a[T[i]]=1;
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int len=p[i].second-p[i].first+1;
		int ans=query(1,p[i].first,p[i].second);
		if(ans>(len-ans))return 1;
	}
	return 0;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>p[i].first>>p[i].second;
	cin>>q;
	for(int i=1;i<=q;i++)
		cin>>T[i];
	int l=1,r=q,ans=q;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	while(ans>=1&&check(ans-1))ans--;
	if(!check(ans))cout<<-1<<endl;
	else cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1 0 1 1 0


*/