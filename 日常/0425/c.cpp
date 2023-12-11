#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
ll p[maxn];
ll n,k;
struct nodea{
	ll x,y;  
    bool operator <(const nodea &a)const{
    	if(a.x!=x)return a.x <x;
    		return a.y>y;
    	}  
};
struct nodeb{
	ll x,y;  
    bool operator <(const nodeb &a)const{
    	if(a.x!=x)return a.x >x;
    		return a.y>y;
    	}  
};
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	ll ans=0;
	ll l=1,r=1,ma=p[1],mi=p[1];
	set<nodea>x;
	set<nodeb>y;
	while(l<=n)
	{
		if(r<l)r=l;
		while(abs(p[r]-ma)<=k&&abs(p[r]-mi)<=k&&r<=n)
		{
			x.insert({p[r],r});
			y.insert({p[r],r});
			mi=min(mi,p[r]);
			ma=max(ma,p[r]);
			r++;
		}
		r--;
		nodea u=*x.begin();
		nodeb v=*y.begin();
		
		if(u.x-v.x==k)
		{
			ans+=r-max(u.y,v.y)+1;		
		}
		x.erase({p[l],l});
		y.erase({p[l],l});

		if(x.size()==0)
		{
			l++;
			ma=mi=p[l];
			continue;
		}
		u=*x.begin();
		v=*y.begin();

		mi=v.x;
		ma=u.x;
		l++;
	}
	cout<<ans<<endl;
}