#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int ans[N];
int a[N],maxn[N];
void solve()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn[i]=ans[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		if(q>=a[i])
			ans[i]=1;
	}
	for(int i=n;i>=1;i--)
	{
		maxn[i]=maxn[i+1];
		if(ans[i]==1)
		{
			maxn[i]=max(maxn[i],a[i]);
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(ans[i]==0)
		{
			if(q-1>=maxn[i])
			{
				q--;
				ans[i]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i];
	cout<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
}