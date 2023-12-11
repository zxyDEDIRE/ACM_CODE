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
const int maxn=1e6;
struct node{
	int l,r,val;
}t[maxn<<2];
int p[maxn];
int n;
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].val=0;
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void update(int rt,int l,int c)
{
	if(t[rt].l==t[rt].r)
	{
		t[rt].val+=c;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,c);
	else update(rt<<1|1,l,c);
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}
void solve()
{
	cin>>n;
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]<i)
		{
			update(1,p[i],1);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i]<i)
		{
			ans+=query(1,i+1,n);
			//update(1,p[i],-1);
		}
	}
	cout<<ans<<endl;
}
signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}
/*
1 0 1 0 1 1 1 1 1 1 
1 2 1 2 1 0 0 0 1 0
1 
*/