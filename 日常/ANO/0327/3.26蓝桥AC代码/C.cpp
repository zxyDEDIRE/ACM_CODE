#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
int main()
{
	int p[]={100,50,20,10,5,1};
	ll ans=0;
	cin>>n;
	for(int i=0;i<=5;i++)
	{
		ans+=n/p[i];
		n=n%p[i];
	}
	cout<<ans<<endl;
	return 0;
}