#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;

long long ksm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cout<<ksm(ksm(m-1,mod-2)*(m-i)%mod,n)<<" ";
	}
	return 0;
}