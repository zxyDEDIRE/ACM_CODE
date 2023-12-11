#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cout.tie(0);cout.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll p[maxn];
int n;
void solve()
{
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;i++)
		cin>>p[i],sum+=p[i];
	if(sum!=0){cout<<"NO\n";return ;}

	ll ans=0,fl=1;
	for(int i=n;i>=1;i--)
	{
		if(p[i]==0&&fl)continue;
		fl=0;
		ans+=p[i];
		if(ans>0){cout<<"NO\n";return ;}
		if(ans==0&&i!=1){cout<<"NO\n";return ;}
	}
	cout<<"YES\n";
}
int main()
{	ios
	int __;cin>>__;
	while(__--)
		solve();	
}