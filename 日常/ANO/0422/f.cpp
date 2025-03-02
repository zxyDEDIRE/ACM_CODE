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
	cin.tie(0);cout.tie(0);

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
		
		cout<<"L";
		cout<<l<<" "<<r<<" ";
		cout<<mi<<" "<<ma<<endl;
		if(u.x-v.x==k)
		{
			ans+=r-max(u.y,v.y)+1;
			cout<<l<<" "<<r<<" "<<max(u.y,v.y)<<" "<<ans<<endl;
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
/*
9 4
6 6 4 4 5 8 8 9 5
13

4 2
1 2 3 1
4

5 1
1 3 2 4 1
1

10 7
2 7 1 8 2 8 1 8 2 8
36

10 4
9 9 9 9 9 5 5 5 5 5
25

7 4
4 5 4 8 9 4 8
4
*/