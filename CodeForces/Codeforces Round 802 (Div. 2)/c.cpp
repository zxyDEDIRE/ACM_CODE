#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];


	ll a=0,b=0;
	ll ans=0;
	ll mi=1e10;


	for(int i=1;i<n;i++)
	{
		p[i+1]-=b;
		if(p[i]<p[i+1])
		{
			ll t=p[i+1]-p[i];
			ans+=t;
			b+=t;
			p[i+1]=p[i];
		}
		else if(p[i]>p[i+1])
		{
			ll t=p[i]-p[i+1];
			ans+=t;
			a+=t;
		}
	}
	ans+=abs(p[n]);
	cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}
/*
10 4 7
6 +3 +4

4 -4 4 -4

4 -4 

*/