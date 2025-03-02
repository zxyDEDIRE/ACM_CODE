#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int maxn=1e6+100;
struct Seg{
	int l,r,val;
	Seg operator+(const Seg&a)const{
		Seg now;
		now.l=l;now.r=a.r;
		now.val=val+a.val;
		return now;
	}
}t[maxn<<2];
int p[maxn];
int n,len;
void build(int rt,int l,int r){
	t[rt]={l,r,0};
	if(l==r)return;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void add(int rt,int l){
	if(t[rt].l==t[rt].r){
		t[rt].val++;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)add(rt<<1,l);
	else add(rt<<1|1,l);
	t[rt]=t[rt<<1]+t[rt<<1|1];
}
int query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}
int q(int x)
{
	int l=1,r=len,ans=r;
	auto check=[&](int mid)->bool{
		return query(1,1,mid)>=x;
	};
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	while(ans>1&&check(ans-1))ans--;
	return ans;
}
void solve()
{
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++)
		cin>>p[i],v[i]=p[i];
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	len=v.size();
	build(1,1,len);
	for(int i=0;i<n;i++)
	{
		int x=p[i];
		x=lower_bound(v.begin(),v.end(),x)-v.begin()+1;
		add(1,x);
		int mid_1=ceil(1.0*(i+1)/3);
		int mid_2=ceil(2.0*(i+1)/3);
		int pos1=q(mid_1)-1;
		int pos2=q(mid_2)-1;
		cout<<v[pos1]<<" "<<v[pos2]<<"\n";
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}