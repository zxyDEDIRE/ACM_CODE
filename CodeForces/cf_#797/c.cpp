#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll a[maxn],b[maxn];
ll n;
void solve()
{
	cin>>n;
	ll t=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];

	for(int i=1;i<=n;i++)
	{
		t=max(t,a[i]);
		cout<<b[i]-t<<" ";
		t=max(t,b[i]);
	}
	cout<<endl;
}
int main()
{
	int __;cin>>__;
	while(__--)solve();
}