#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
ll p[maxn],sum[maxn];
ll n,a,b,ans,s,fl;
void solve()
{
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
		cin>>p[i],sum[i]=0;
	for(int i=n;i>=1;i--)
		sum[i]+=sum[i+1]+p[i];
//	for(int i=1;i<=n;i++)
//		cout<<sum[i]<<" ";
//	cout<<endl;
	ans=0,s=0,fl=0;p[n+1]=0;
	for(int i=1;i<=n;i++)
	{
		ans+=b*(p[i]-s);
		ll qi=a*(p[i]-s);
	//	ll y=sum[fl+1]-sum[n+1]-(i-fl)*b;
		ll y=(p[i]-s)*(n-s);
	//	cout<<sum[fl+1]<<" "<<sum[n+1]<<endl;
		cout<<p[i]-s<<" "<<n-s<<endl;
		cout<<qi<<" "<<y<<endl;
		cout<<endl;
	//	cout<<endl;
		if(qi<=y)
		{
			ans+=qi;
			s=p[i];
			fl=i;
		}
	}
	cout<<ans<<endl;
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)solve();
}
/*
5 6 3
1  5  6  21 30
63 62 57 51 30

6 3*(62)
*/