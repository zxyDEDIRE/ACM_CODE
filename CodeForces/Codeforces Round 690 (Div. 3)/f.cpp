#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct Seg{int l,r,val,lazy,ma;}t[maxn];
struct node{int x,y;
}p[maxn];
int n;
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		t[rt<<1].val+=t[rt].lazy*(t[rt<<1].r-t[rt<<1].l+1);
		t[rt<<1|1].val+=t[rt].lazy*(t[rt<<1|1].r-t[rt<<1|1].l+1);
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1|1].lazy+=t[rt].lazy;
		t[rt].lazy=0;
	}
}
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void update(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].val+=(t[rt].r-t[rt].l+1);
		t[rt].lazy+1;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r);
	if(r<mid)update(rt<<1|1,l,r);
	pushup(rt);
}
int query(int rt,int l)
{
	if(t[rt].l==l&&t[rt].r==l)
	{
		return t[rt].val;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)return query(rt<<1,l);
	else return query(rt<<1|1,l);
}
void solve()
{
	cin>>n;
	map<int,bool>mp;
	vector<int>v;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].x>>p[i].y;
		if(!mp[p[i].x])mp[p[i].x]=1,v.push_back(mp[p[i].x]);
		if(!mp[p[i].y])mp[p[i].y]=1,v.push_back(mp[p[i].y]);
	}
	build(1,1,2*n);
	sort(v.begin(),v.end());
	for(int i=1;i<=n;i++)
	{
		int x=lower_bound(v.begin(),v.end(),p[i].x)-v.begin()+1;
		int y=lower_bound(v.begin(),v.end(),p[i].y)-v.begin()+1;
		update(1,x,y);
	}
	int ma=0;
	for(auto i:v)
		ma=max(ma,query(1,i+1));
	cout<<ma<<endl;
	cout<<n-ma<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}