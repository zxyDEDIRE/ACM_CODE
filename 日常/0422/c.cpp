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
	queue<int>ma,mi;
	set<node>s;
	int x=p[1],y=p[1],ans=0;
	int l=1,r=1;
	while(l<=n)
	{
		while(abs(p[r]-x)<=k&&abs(p[r]-y)<=k&&r<=n)
		{
			s.insert(node(p[r],r));
			if(p[r]>y){
				while(ma.size())ma.pop();
				ma.push(r);y=p[r];}
			else if(p[r]==y)ma.push(r);
			if(p[r]<x){
				while(mi.size())mi.pop();
				mi.push(r);x=p[r];}
			else if(p[r]==x)mi.push(r);
			r++;
		}
		r--;
		if(y-x==k&&mi.size()&&ma.size())
		{
			ans+=r-max(mi.front(),ma.front())+1;
			cout<<l<<" "<<r<<" "<<max(mi.front(),ma.front())<<" "<<ans<<endl;
			if(p[l]==x)mi.pop();
			if(p[l]==y)ma.pop();
		}
		
		if(l==4||l==5||l==6)
		{
			cout<<mi.size()<<" "<<ma.size()<<endl;
			cout<<x<<" "<<y<<endl;
			cout<<l<<" "<<r<<endl;
			cout<<endl;
		}

		s.erase(node(p[l],l));
		l++;
		if(mi.empty())
		{
			node t=*s.begin();
			x=t.x;
			mi.push(t.y);
		}
		if(ma.empty())
		{
			node t=*s.rbegin();
			y=t.x;
			ma.push(t.y);
		}
	}
	cout<<ans<<endl;
}
/*
9 4
6 6 4 4 5 8 8 9 5
6 6 4 4 5 8
6 6 4 4 5 8 8
  6 4 4 5 8
  6 4 4 5 8 8
    4 4 5 8
    4 4 5 8 8
      4 5 8
      4 5 8 8
        5 8 8 9
        5 8 8 9 5
          8 8 9 5
            8 9 5
              9 5
4 2
1 2 3 1

5 1
1 3 2 4 1

5 0
1 1 1 1 1

10 7
2 7 1 8 2 8 1 8 2 8
2 7 1 8         7 7
  7 1 8         7 14
    1 8         7 21
      8 2 8 1   4 25
        2 8 1   4 29
          8 1   4 33
            1 8 3 36

10 4
9 9 9 9 9 5 5 5 5 5

7 4
4 5 4 8 9 4 8
4 5 4 8
  5 4 8
    4 8
*/