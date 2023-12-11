/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
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
	int l,r,id,val;
}t[maxn];
int n;
void build(int rt,int l,int r){
	t[rt]={l,r,l,0};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void update(int rt,int l,int k){
	if(t[rt].l==t[rt].r){
		t[rt].val=k;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,k);
	else update(rt<<1|1,l,k);
	if(t[rt<<1].val>t[rt<<1|1].val)
		t[rt].val=t[rt<<1].val,t[rt].id=t[rt<<1].id;
	else t[rt].val=t[rt<<1|1].val,t[rt].id=t[rt<<1|1].id;
}
pii query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
		return {t[rt].val,t[rt].id};
	int mid=(t[rt].l+t[rt].r)>>1;
	pii ans={0,0};
	if(l<=mid){
		auto x=query(rt<<1,l,r);
		if(x.first>ans.first)ans=x;
	}
	if(r>mid){
		auto x=query(rt<<1|1,l,r);
		if(x.first>ans.first)ans=x;
	}
	return ans;
}
void solve()
{
	cin>>n;
	build(1,1,n);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		if(x==0)
		{
			auto now=query(1,1,i);
			ans+=now.first;
			update(1,now.second,0);
		}
		else update(1,i,x);
	}
	cout<<ans<<endl;
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