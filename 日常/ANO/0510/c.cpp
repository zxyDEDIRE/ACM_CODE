#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6;
struct node{
	int l,r,val,cnt;
}t[maxn];
int p[maxn];
int n,ans;
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].cnt=0;
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushup(int rt)
{
	t[rt].cnt=t[rt<<1].cnt+t[rt<<1|1].cnt;
}
void update(int rt,int k)
{
	if(t[rt].l==k&&t[rt].r==k){
		ans+=t[rt].cnt;
		t[rt].cnt++;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(k<=mid){
		ans+=t[rt<<1|1].cnt,update(rt<<1,k);
	}
	else update(rt<<1|1,k);
	pushup(rt);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	build(1,1,n);
	ans=0;
	for(int i=1;i<=n;i++)
	{
		update(1,p[i]);
		cout<<ans<<endl;
	}
	cout<<ans<<"\n";
}
signed main(){
	int __;cin>>__;
	while(__--)solve();
}