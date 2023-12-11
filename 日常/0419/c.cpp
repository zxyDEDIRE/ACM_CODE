#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int p[maxn];
int n;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int res=1e18;
	for(int k=1;k<=n;k++)
	{
		int ans=0;
		int s=0;
		for(int i=k-1;i>=1;i--)
		{
			int t=s/p[i]+1;
			ans+=t;
			s=t*p[i];
		}
		s=0;
		for(int i=k+1;i<=n;i++)
		{
			int t=s/p[i]+1;
			ans+=t;
			s=t*p[i];
		}
		res=min(res,ans);
	}
	cout<<res<<endl;
}
/*
5
5
4

7
2
10

8
8
16
*/