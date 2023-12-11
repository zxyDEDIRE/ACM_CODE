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
ll n,k,g;
void solve()
{
	cin>>n>>k>>g;
	if(g==1||g==2){
		cout<<0<<endl;
		return ;
	}
	ll tot=k*g;
	ll a = ceill(0.5*g)-1;
	ll b = a*n;
	ll ans=0;
	if(tot>b)
	{
		ans+=(n-1)*a;
		tot-=ans;
		ll r=tot%g;
		if(r<ceill(0.5*g))ans+=r;
		else 
		{
			ll ned = g-r;
			if(ans>=ned)ans=ans-ned;
			else ans=max((g-(r+ans)),ans-(g-r));
		}
	}
	else ans=tot;
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1
3 4 3

1 1 10

1
1000000000 1000000000 1000000000
*/