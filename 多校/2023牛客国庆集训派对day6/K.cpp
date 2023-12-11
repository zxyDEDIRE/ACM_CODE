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
const int maxn=1e6+100;
struct node{
	int l,r,val;
}t[maxn];
int p[maxn];
int a[maxn];
int n,k;
void pushup(int rt){
	t[rt].val=min(t[rt<<1].val,t[rt<<1|1].val);
}
void build(int rt,int l,int r){
	t[rt]={l,r,INF};
	if(l==r){
		t[rt].val=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
int query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=INF;
	if(l<=mid)ans=min(ans,query(rt<<1,l,r));
	if(r>mid)ans=min(ans,query(rt<<1|1,l,r));
	return ans;
}
void solve()
{
	cin>>n>>k;
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]>k)flag=0;
	}
	if(!flag){
		cout<<"NO\n";
		return ;
	}
	map<int,int>mp;
	for(int i=n;i>=1;i--)
	{
		if(!mp.count(p[i]))mp[p[i]]=INF;
		a[i]=mp[p[i]];
		mp[p[i]]=i;
	}
	build(1,1,n);
	for(int j=1;j<=min(n,k);j++)
	{
		int flag=1;
		int now;
		now=query(1,1,j);
		if(now<=j)flag=0;
		for(int l=j+1;l<=n;l+=k)
		{
			if(!flag)break;
			int r=min(n,l+k-1);
			now=query(1,l,r);
			if(now<=r)flag=0;
		}
		if(flag){
			cout<<"YES\n";
			return ;
		}
	}
	cout<<"NO\n";
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
/*
2 3 1 2 3 1 2 3 1 2 3 1 1
*/