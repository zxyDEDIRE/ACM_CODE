#include<bits/stdc++.h>
using namespace std;
int n,m;
long long tp=1e18;
void solve()
{
	__int128 nn=n;
	__int128 t=1;
	m=min(m,n-m);
	__int128 ans=1;
	for(int i=1;i<=m;i++)
	{
		ans=ans*nn/t;
		nn--;t++;
		if(ans>=tp)
		{
			cout<<tp<<'\n';
			return;
		}
	}
	long long res=ans;
	cout<<res<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	while(cin>>n>>m)
		solve();
	return 0;
}
