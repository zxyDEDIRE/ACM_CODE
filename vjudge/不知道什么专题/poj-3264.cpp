/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct Seg{
	int l,r,mi,ma;
}t[maxn];
int n,q;
void pushup(int rt)
{
	t[rt].ma=max(t[rt<<1].ma,t[rt<<1|1].ma);
	t[rt].mi=min(t[rt<<1].mi,t[rt<<1|1].mi);
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r)
	{
		int x;cin>>x;
		t[rt].ma=t[rt].mi=x;
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
	{
		return pii(t[rt].mi,t[rt].ma);
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	pii ans;
	ans.first=INF;
	ans.second=0;
	if(l<=mid)
	{
		pii x=query(rt<<1,l,r);
		ans.first=min(ans.first,x.first);
		ans.second=max(ans.second,x.second);
	}
	if(r>mid)
	{
		pii x=query(rt<<1|1,l,r);
		ans.first=min(ans.first,x.first);
		ans.second=max(ans.second,x.second);
	}
	return ans;
}
void solve()
{
	cin>>n>>q;
	build(1,1,n);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		pii ans=query(1,x,y);
		cout<<ans.second-ans.first<<endl;
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
        solve();
    return 0;
}