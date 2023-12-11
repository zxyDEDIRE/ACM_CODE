#include<bits/stdc++.h>
using namespace std;

const int N=5010;
long long sum[N];
long long a[N];
long long n,d;
long long  f(long long  x,long long l,long long r)
{
	if(x>r)return r;
	else if(x<l)return l;
	return x;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		long long l=a[i];
		long long r=l+d;
		long long now=0;
		long long NOW=0;
		for(int j=1;j<n;j++)
		{
			now+=abs(f(a[j],l,r)-f(a[j+1],l,r));
			NOW+=abs(f(a[j],l-d,l)-f(a[j+1],l-d,l));
		}
		ans=max(ans,now);
		ans=max(ans,NOW);
	}
	cout<<ans<<endl;
	return 0;
}
/*
2 2
1 5
*/