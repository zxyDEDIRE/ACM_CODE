#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
void solve()
{
	ll n;
	cin>>n;
	ll t=n/3;
	if(n%3==0)cout<<t<<" "<<t+1<<" "<<t-1<<endl;
	else if(n%3==1)cout<<t<<" "<<t+2<<" "<<t-1<<endl;
	else if(n%3==2)cout<<t+1<<" "<<t+2<<" "<<t-1<<endl;
}
int main()
{
	int __;cin>>__;
	while(__--)solve();
}