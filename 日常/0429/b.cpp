#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int f[maxn][30];
int p[maxn];
int n,k;
struct nodea{
	int x,y;  
    bool operator <(const nodea &a)const{
    	if(a.x!=x)return a.x <x;
    		return a.y>y;
    	}  
    nodea(int a,int b){x=a,y=b;}
};
struct nodeb{
	int x,y;  
    bool operator <(const nodeb &a)const{
    	if(a.x!=x)return a.x >x;
    		return a.y>y;
    	}  
    nodeb(int a,int b){x=a,y=b;}
};
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int ans=0;
	int l=1,r=1,ma=p[1],mi=p[1];
	set<nodea>x;
	set<nodeb>y;
	while(l<=n)
	{
		if(r<l)r=l;
		while(abs(p[r]-ma)<=k&&abs(p[r]-mi)<=k&&r<=n)
		{
			x.insert(nodea(p[r],r));
			y.insert(nodeb(p[r],r));
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
		x.erase(nodea(p[l],l));
		y.erase(nodeb(p[l],l));

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