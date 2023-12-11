#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e4;
int n,m;
void solve()
{
	cin>>n>>m;

	ll ansa=0;
	ansa=(1+m)*m/2;
	ll s=m;
	for(int i=2;i<=n;i++)
	{
		s+=m;
		ansa+=s;
	}

	ll ansb=0;
	s=1;
	for(int i=1;i<n;i++)
	{
		ansb+=s;
		s+=m;
	}
	for(int i=1;i<=m;i++)
	{
		ansb+=s;
		s++;
	}

	cout<<min(ansa,ansb)<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}