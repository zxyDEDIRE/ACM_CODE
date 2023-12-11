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
const int maxn=1e6+1000;
struct node{
	ll w,val;
}p[maxn];
ll pre[maxn],suf[maxn];
int n,m,k;

void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i].w;
	for(int i=1;i<=n;i++)
		cin>>p[i].val;
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.val!=b.val)return a.val<b.val;
		return a.w<b.w;
	});
	if(k==1)
	{
		for(int i=n;i>=1;i--)
			if(p[i].w<=m){
				cout<<p[i].val<<endl;
				return ;
			}
		cout<<-1<<endl;
		return ;
	}
	multiset<ll>s;
	ll sum=0;
	int mid=k/2;
	for(int i=1;i<=n;i++)
	{
		if(s.size()<mid)s.insert(p[i].w),sum+=p[i].w;
		else
		{
			auto fl=s.rbegin();
			if(*fl>p[i].w)sum-=*fl,s.erase(s.find(*fl)),sum+=p[i].w,s.insert(p[i].w);
		}
		pre[i]=sum;
	}
	s.clear();
	sum=0;
	for(int i=n;i>=1;i--)
	{
		if(s.size()<mid)s.insert(p[i].w),sum+=p[i].w;
		else
		{
			auto fl=s.rbegin();
			if(*fl>p[i].w)sum-=*fl,s.erase(s.find(*fl)),sum+=p[i].w,s.insert(p[i].w);
		}
		suf[i]=sum;
	}
	// for(int i=1;i<=n;i++)
	// 	cout<<pre[i]<<" ";cout<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<suf[i]<<" ";cout<<endl;
	for(int i=n-mid;i>mid;i--)
	{
		ll now=suf[i+1]+pre[i-1]+p[i].w;
		if(now<=m){
			cout<<p[i].val<<endl;
			return ;
		}
	}
	cout<<-1<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
5 10 3
1 2 3 4 5
1 2 3 4 5
*/