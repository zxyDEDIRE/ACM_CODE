#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int f[maxn][30];
int p[maxn];
int n,k;
struct node{
	int x,y;  
    bool operator <(const node &a)const{
    	if(a.x!=x)return a.x >x;
    		return a.y<y;
    	}  
    node(int a,int b){x=a,y=b;}
};
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int x=p[1],y=p[1],ans=0;
	int l=1,r=1;
	set<node>s;
	while(l<=n)
	{
		while(abs(p[r]-x)<=k&&abs(p[r]-y)<=k&&r<=n)
		{
			s.insert(node(p[r],r));
			x=min(x,p[r]);
			y=max(y,p[r]);
			r++;
		}
		r--;
		node u=*s.begin();
		node v=*s.rbegin();

		if(v.x-u.x==k)
		{
			ans+=r-max(u.y,v.y)+1;
			cout<<u.x<<" "<<v.x<<endl;
			cout<<l<<" "<<r<<" "<<max(u.y,v.y)<<" "<<ans<<endl;
		}
		s.erase(node(p[l],l));
		if(s.size()==0){
			l++;
			continue;
		}
		u=*s.begin();
		v=*s.rbegin();
		x=u.x;
		y=v.x;
		l++;
	}
	cout<<ans<<endl;
}