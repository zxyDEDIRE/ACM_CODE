#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
const int mod=1e9+7;

int mull(int a,int b)
{
	int qw=0;
	while(b)
	{
		if(b&1)qw=(qw+a)%mod;
		a=(a+a)%mod;
		b>>=1;
	}
	return qw;
}

signed main(){
	int a,b;
	cin>>a>>b;
	cout<<mull(a,b)<<endl;
}
/*
22
2

4
40
*/
