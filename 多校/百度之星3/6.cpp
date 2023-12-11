/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct Seg{
	int l,r,val,ma;
}t[maxn<<2];
int n,m;
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
	t[rt].ma=max(t[rt<<1].ma,t[rt<<1|1].ma);
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	cout<<l<<" "<<r<<" "<<rt<<endl;
	if(l==r){
		cin>>t[rt].val;
		t[rt].ma=t[rt].val;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
int ans=0;
int sum(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=sum(rt<<1,l,r);
	if(r>mid)ans+=sum(rt<<1|1,l,r);
	return ans;
}
void query(int rt,int l,int r)
{
	
}
void solve()
{
	cin>>n>>m;
	build(1,1,n);
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		if(x>y)swap(x,y);
		ans=0;
		query(1,x,y);
		cout<<ans<<endl;
	}
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3 1 5 2 4
2 4

1 5 2
1 25 10
*/