#include<bits/stdc++.h>
using namespace std;

const int N=5010;
long long sum[N];
int a[N];
int n,d;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1) sum[i]=sum[i-1]+abs(a[i]-a[i-1]);

	}
	long long ans=-1e18;
    for(int i=0;i<=d;i++)
    {
    	for(int l=1;l+d<=n;l++)
    	{
    		int r=l+d;
    		long long w=0;
    		if(l>1) w+=abs(l-a[l]);
    		if(r<n) w+=abs(r-a[r]);
    		ans=max(ans,sum[l+d]-sum[l]+w);
    	}
    }
    cout<<ans;
	return 0;
}