/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
const int mod=2147493647;
ll fp(ll b,ll p)
{
	ll r=1ll;
	b%=mod;
	p%=mod;
	while(p)
	{
		if(p%2)r=(r*b)%mod;
		b=(b*b)%mod;
		p>>=1;
	}
	return r%mod;
}
ll p[maxn];
ll n,a,b;
void solve()
{
	cin>>n>>p[1]>>p[2];
	for(int i=3;i<=n;i++)
	{
		p[i]=(((p[i-2]*2)%mod+p[i-1])%mod+fp(i,4))%mod;
	}
	cout<<p[n]<<endl;
}
signed main(){
 // freopen("C:\Users\tob\Desktop\P4391_9.in.txt","r",stdin);
 // freopen("C:\Users\tob\Desktop\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}