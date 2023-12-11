#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;
map<int,int>mp,li;
int p[maxn],t[maxn];
set<int>s;
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i],mp[p[i]]++;
	for(int i=1;i<=m;i++)
	{
		int x;cin>>t[i]>>x;
		li[t[i]]=x;
		if(x==0)s.insert(t[i]);
	}
	sort(p+1,p+1+n);
	sort(t+1,t+1+m);
	int ans=0;
	for(int i=1,j=1;i<=m;i++)
	{
		while(j<n&&p[j]<i)j++;
		while(1)
		{
			
		}
		while(*s.begin()<=i)s.erase(*s.begin());
	}
}
signed main()
{
	int __;cin>>__;
	while(__--)
		solve();
}