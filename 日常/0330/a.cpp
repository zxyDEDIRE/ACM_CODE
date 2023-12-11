#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=998244343;
bool su(int x)
{
	if(x==1)return 0;
	if(x==2||x==3)return 1;
	if(x%6!=5&&x%6!=1)return 0;
	int tmp=sqrt(x);
	for(int i=5;i<=tmp;i+=6)
		if(x%i==0||x%(i+2)==0)
			return 0;
	return 1;
}
void solve()
{
	ll x,y,n,ans=0;
	cin>>x>>y;x++;
	while(su(x)==0)x++;
	cout<<x<<endl;
	n=y;
	while(n<=x)
	{
		ans=(ans+x/n)%mod;
		n*=y;
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)solve();
}
/*
2 4 6 8 10
*/