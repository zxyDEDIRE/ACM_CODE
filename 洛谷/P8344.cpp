#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
void solve()
{
	ll x,y,z;
	cin>>x>>y>>z;
	ll a=z-1;
	ll b=(1+(z-1))*(z-1)/2-1;
	if(x<=a&&y<=b)cout<<"Renko"<<endl;
	else cout<<"Merry"<<endl;
}
int main()
{
	int __;cin>>__;
	while(__--)solve();
}
/*
z-1+z-2
*/