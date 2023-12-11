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
using ll=long long;
using pii=pair<int,int>;
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
ll a[10],b[10];
int n=7,m;
int fp(int b,int p)
{
	int res=1;
	while(p)
	{
		if(p&1)res=(res*b)%mod;
		p>>=1;
		b=(b*b)%mod;
	}
	return res;
}
int A(int x,int y)
{
	int ans=1;
	for(int i=x,j=1;j<=y;i--,j++)
		ans*=i;
	return ans;
}
int C(int x,int y)
{

	int ans=1;
	int a=1,b=1;
	for(int i=1;i<=y;i++)
	{
		a*=x;x--;
		b*=i;
	}
	return a/b;
}
void solve()
{
	// for(int i=1;i<=n;i++)
	// 	cin>>a[i],a[i]=(a[i]+9)/10;
	// for(int i=1;i<=n;i++)
	// 	cin>>b[i],b[i]=(b[i]+9)/10;
	n=1,m=1;
	int sum=fp(2,n+m);
	int ans=0;
	for(int i=m-1;i<=n+m-2;i++)
	{
		int x=1;
		x=C(i,m-1);
		for(int j=i+1;j<n+m;j++)
			x*=2;
		ans+=x;
	}
	cout<<ans<<" "<<sum<<endl;
	
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
111 
112 
121 
211 
122
212
221 +1
222 +1


1111
1112
1121
1211
2111
1122
1212 
2112

1221 +1
1222 +1

2121 +1
2122 +1

2211 +1
2212 +1

2221 +1
2222 +1

14

*/