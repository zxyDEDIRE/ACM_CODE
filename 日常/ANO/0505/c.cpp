#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
const int maxn=1e6;
ll a,b,c,x,y;
void solve()
{
	cin>>a>>b>>c>>x>>y;
	x-=min(x,a);
	y-=min(y,b);
	if(c>=x+y)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
int main(){
	int __;cin>>__;
	while(__--)solve();
}
/*

*/