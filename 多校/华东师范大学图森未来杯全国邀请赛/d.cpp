#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1005;
struct node
{
	int x,y;
	bool operator==(const node& tmp)
	{
		return (x==tmp.x)&&(y==tmp.y);
	}
}t[maxn];
int dis(node a,node b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool check(node a,node b,node c,node d)
{
	if(a==b||a==c||a==d||b==c||b==d||c==d)
		return 0;
	if(dis(a,b)!=0 && dis(a,b)==dis(b,c) && dis(a,b)==dis(c,d) && dis(a,b)==dis(d,a) && dis(a,c)==dis(b,d))
		return 1;
	if(dis(a,b)!=0 && dis(a,b)==dis(b,d) && dis(a,b)==dis(d,c) && dis(a,b)==dis(c,a) && dis(a,d)==dis(b,c))
		return 1;
	if(dis(a,c)!=0 && dis(a,c)==dis(c,b) && dis(a,c)==dis(b,d) && dis(a,c)==dis(d,a) && dis(a,b)==dis(c,d))
		return 1;
	return 0;
}
bool solve()
{
	int n,m;cin>>n>>m;
	if(m!=4)
		return 0;
	for(int i=0;i<n;i++)
		cin>>t[i].x>>t[i].y;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				for(int u=k+1;u<n;u++)
					if(check(t[i],t[j],t[k],t[u]))
						return 1;
	return 0;
}
signed main()
{
	puts(solve()?"Yes":"No");
	return 0;
}