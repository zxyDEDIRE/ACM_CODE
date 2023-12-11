#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct node{
	ll l,r;
}p[maxn];
ll n,xx,rr;
void solve()
{
	cin>>n;
	cin>>xx>>rr;
	for(int i=1;i<n;i++)
	{
		ll x,r;
		cin>>x>>r;
		p[i].l=x-r;
		p[i].r=x+r;
	}
	p[n].l=xx-rr;
	p[n].r=xx+rr;
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.l!=b.l)return a.l<b.l;
		else return a.r<b.r;
	});

	ll s=p[1].r;
	ll ans=0;
	for(int i=2;i<=n;i++)
	{
		if(s<p[i].l)ans+=p[i].l-s;
		s=max(s,p[i].r);
	}
	cout<<ans<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
2 3 3
*/