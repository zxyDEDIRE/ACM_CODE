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
//	freopen("C:\\Users\\tob\\Desktop\\S\\in1.in","r",stdin);
//	freopen("C:\\Users\\tob\\Desktop\\S\\in1.out","w",stdout);
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
			x.insert(nodea{p[r],r});
			y.insert(nodeb{p[r],r});
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
		x.erase(nodea{p[r],r});
		y.erase(nodeb{p[r],r});

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
//	fclose(stdin);
//	fclose(stdout);
}
/*
9 4
6 6 4 4 5 8 8 9 5

13
*/