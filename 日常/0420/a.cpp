#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<ll,bool>mp;
ll n,ans;
int main()
{
	cin>>n;
	int flag=1;
	while(n!=1)
	{
	//	cout<<n<<endl;
		if(mp[n])
		{
			flag=0;
			break;
		}
		mp[n]=1;
		if(n&1)
		{
			ans+=n+1;
			n=(n+1)/2*3-1;
		}
		else
		{
			ans+=n;
			n=n/2;
		}
	}
	if(flag)cout<<ans<<endl;
	else cout<<-1<<endl;
}
/*
aaa
cbc
caaa
aaaaa
*/