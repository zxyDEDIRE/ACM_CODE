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
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
ll mod=998244353;
struct node{
	ll num,l,r;
};
struct Seg{
	int l,r;
	__int128 val;
}t[maxn<<1];
ll pre[maxn];
ll w[maxn];
int n;
void pushup(int rt){
	t[rt].val=t[rt<<1].val*t[rt<<1|1].val;
	if(t[rt].val>mod)t[rt].val=0;
}
void build(int rt,int l,int r){
	t[rt]={l,r,0};
	if(l==r){
		t[rt].val=w[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
__int128 query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	int mid=(t[rt].l+t[rt].r)>>1;
	__int128 ans=1;
	if(l<=mid)ans=ans*query(rt<<1,l,r);if(ans>=mod)ans=0;
	if(r>mid)ans=ans*query(rt<<1|1,l,r);if(ans>=mod)ans=0;
	return ans;
}
ll sum(int l,int r){
	return pre[r]-pre[l-1];
}
void max(node &a,ll num,ll l,ll r){
	if(num>a.num)a={num,l,r};
}
void solve()
{
	cin>>n;
	vector<int>v;
	for(int i=1;i<=n;i++){
		cin>>w[i];pre[i]=pre[i-1]+w[i];
		if(w[i]>1)v.push_back(i);
	}
	mod=pre[n];
	build(1,1,n);

	if(v.size()<2)
	{
		cout<<"1 1\n";
	}
	else
	{
		ll ch=query(1,1,n);
		if(ch==0){
			cout<<v[0]<<" "<<v.back()<<endl;
			return ;
		}
		ll ans=sum(1,n);
		n=v.size();
		ll L=1,R=1;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				ll now=query(1,v[i],v[j])+sum(1,n)-sum(v[i],v[j]);
				if(now>ans)
				{
					ans=now;
					L=v[i];
					R=v[j];
				}
			}
		}
		cout<<L<<" "<<R<<endl;

	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}