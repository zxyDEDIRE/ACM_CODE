#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int maxn=1e6+7;
int n,a[maxn],x[maxn];
struct node{int l,r,id;};
pii l[maxn],r[maxn];
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
		cin>>a[i];
	a[0]=a[n]=0;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	int now=0;
	for(int i=1;i<=n;i++)
	{
		l[i]={now,now+x[i]};
		now+=a[i]+x[i];
	}
	now=0;
	for(int i=n;i>=1;i--)
	{
		r[i]={now,now+x[i]};
		now+=a[i-1]+x[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(l[i].first>r[i].second)
			continue;
		if(r[i].first>l[i].second)
			continue;
		ans+=min(l[i].second,r[i].second)-max(l[i].first,r[i].first);
	}
	cout<<ans;
}
/*
5
1 2 3 2
100 2 10
*/