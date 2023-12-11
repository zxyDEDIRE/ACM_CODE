/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int mod=1e9+7;
int n;
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
int fp(int b,int p)
{
	int r=1;
	while(p){
		if(p&1)r=(r*b)%mod;
		p>>=1;
		b=(b*b)%mod;
	}
	return r;
}
void solve()
{
	int n;
	cin>>n;
	int s=mull(mull(n,mull(n+1,2*n+1)),fp(6,mod-2));
	int t=mull(mull(n-1,mull(n,n+1)),fp(3,mod-2));
	// int s=n*(n+1)*(2*n+1)/6;s%=mod;
	// int t=n*(n+1)*(n+2)/3-n*(n+1);t%=mod;
	int ans=(s+t)*2022%mod;
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
