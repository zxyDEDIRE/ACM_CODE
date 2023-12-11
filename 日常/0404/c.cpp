#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
ll p[maxn];
ll n,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];

	for(int i=2;i<n;i++)
	{
		ll a=0,b=0;
		for(int j=1;j<i;j++)
			a+=(p[j]<p[i]);
		for(int j=n;j>i;j--)
			b+=(p[j]>p[i]);
		ans+=a*b;
	}
	cout<<ans<<endl;
}