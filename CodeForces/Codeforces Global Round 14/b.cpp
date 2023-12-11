/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
map<ll,bool>mp;
int n;
void solve()
{
	cin>>n;
	if(mp[n])cout<<"YES\n";
	else cout<<"NO\n";
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	ll s=2,ss=4,cnt=1,k;
	while(1)
	{
		int flag=0;
		k=s*cnt*cnt;
		if(k<=1e9)mp[k]=1,flag++;
		k=4*cnt*cnt;
		if(k<=1e9)mp[k]=1,flag++;
		cnt++;
		if(flag==0)break;
	}
	ll t=4;
	while(1)
	{
		mp[t]=1;
		t*=2;
		if(t>1e9)break;
	}

	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
2 8 32

4 8 16
*/