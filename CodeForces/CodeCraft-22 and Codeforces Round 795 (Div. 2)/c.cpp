#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
void solve()
{
	ll n,k,ans=0;
	string str;
	
	cin>>n>>k>>str;
	vector<int>v;
	for(int i=0;i<str.size();i++)
		if(str[i]=='1')ans+=11,v.push_back(i);

	int len=v.size();
	ll s=k+1;
	ll t=k+1;
	if(len)s=v[0]-0;
	if(len)t=n-v[len-1]-1;

	if(len==0)ans=0;
	else if(len==1)
	{
		if(k>=t)ans-=10;
		else if(k>=s)ans-=1;
	}
	else
	{
		if(k>=t)ans-=10,k-=t;
		if(k>=s)ans-=1,k-=s;;
	}
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)solve();
}
/*
1010
*/