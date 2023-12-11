/*
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
void solve()
{
	ll p,q,b;
	cin>>p>>q>>b;
	ll d=__gcd(p,q);
	q/=d;
	while(q!=1)
	{
		d=__gcd(q,b);
		if(d==1)break;
		while(q%d==0)q/=d;
	}
	if(q==1)puts("YES");
	else puts("NO");
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}