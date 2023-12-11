#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int a,b;
	cin>>a>>b;
	if(b<=a)
	{
		cout<<a-b<<"\n";
		return;
	}
	//b>a
	int ans=b-a;

	if(a<=100000)
	{
		for(int x=0;x<=100000;x++)
		{
			int tmp=a+x;
			if(b>tmp)
			{
				if(b%tmp==0)
				{
					ans=min(ans,x);
				}
				else
				{
					ans=min(ans,x+tmp-b%tmp);	
				}
			}
			else
			{
				ans=min(ans,x+tmp-b);
			}
		}
	}
	else
	{
		for(int d=1;d<=100000;d++)
		{
			int ad=a*d;
			if(ad<=b)
			{
				// (b-ad+y)|d
				int y=(d-b%d)%d;
				int x=(b-ad+y)/d;
				ans=min(ans,x+y);
			}
			else
			{
				int y=ad-b;
				ans=min(ans,y);
			}
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)
		solve();
}
