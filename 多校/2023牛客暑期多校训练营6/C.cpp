/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
ll f(ll x)
{
	ll ans=0;
	ll t=5;
	for(int i=1;i<=26;i++)
	{
		if(t>x)break;
		ans+=x/t;
		t*=5;
	}
	return ans;
}
ll A(ll n,ll T)
{
	ll s=T+1;
	ll t=(n/T)/2*2*T+s;
	while(t>n)t-=T*2;
	


}
ll h(ll n)
{
	ll t=5;
	ll ans=0;
	for(int i=1;i<=25;i++)
	{
		ans+=A(n,t);
	}
}
void solve()
{ 
	ll n;
	cin>>n;
	A(n,5);


	
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/* 
*/