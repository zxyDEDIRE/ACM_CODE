#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int p[maxn];
int n,x,y;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n>>y>>x;
	for(int i=1;i<=n;i++)
		cin>>p[i];

	queue<int>ma,mi;
	int ans=0;
	int l=1,r=1;
	while(l<=n)
	{
		if(r<l)r=l;
		if(p[l]<x||p[l]>y)
		{
			while(ma.size())ma.pop();
			while(mi.size())mi.pop();
			l++;
			continue;
		}
		while(r<=n&&p[r]>=x&&p[r]<=y)
		{
			if(p[r]==x)mi.push(r);
			if(p[r]==y)ma.push(r);
			r++;
		}
		r--;
	//	cout<<l<<" "<<r<<endl;
		while(l<=r&&mi.size()&&ma.size())
		{
			ans+=r-max(mi.front(),ma.front())+1;
		//	cout<<r<<" "<<max(mi.front(),ma.front())<<endl;
		//	cout<<ans<<endl;
			if(p[l]==x)mi.pop();
			if(p[l]==y)ma.pop();
			l++;
		}
		l++;
	}
	cout<<ans<<endl;
}
/*
*/