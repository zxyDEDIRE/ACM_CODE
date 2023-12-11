#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int p[maxn];
int n,x,y;
int f(int up,int down)
{
	int res=0;
	for(int l=1,r=1;r<=n;r++)
	{
		if (p[r] > up || p[r] < down)
				l = r + 1;
			res += r - l + 1;
		cout<<l<<" "<<r<<endl;
	}
	cout<<res<<endl;
	return res;
}
signed main()
{
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	cout<<f(x,y)-f(x-1,y)-f(x,y+1)+f(x-1,y+1)<<endl;
}