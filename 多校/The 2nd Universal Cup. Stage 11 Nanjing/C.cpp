#include<bits/stdc++.h>
using namespace std;

long long p,m;
void solve()
{
	cin>>p>>m;
	long long k=m/p-1;
	k=max(0ll,k);
	long long ans=k;
	__int128 pp=p;
	pp*=(k);
	for(int i=1;i<=5;i++){
		if(((pp+1)^(p-1))<=m){
			ans++;
		}
		pp+=p;
	}
	cout<<ans<<'\n';
}
/*
0100
0010
0101
1111
 1 1 1 1 1
1 1 1 1 1 1
(p)^(p-1)
*/
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __=1;
	cin>>__;
	while(__--)
		solve();
	return 0;
}