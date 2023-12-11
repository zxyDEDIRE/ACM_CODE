/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
void solve()
{
	ll l,r;
	cin>>l>>r;
	ll ans=0;
	for(ll i=1;i<=(r-l);i++)
	{
		int s=(l%i);
		int t=l+((l%i)==0?0:(i-(l%i)))+i;
		cout<<"I "<<i<<" "<<s<<" "<<l/i<<" "<<t<<endl;
		if(t<=r)ans++;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	// ll x=1e9-11;
	// ll y=1e18;
	// ll t=(1e18)-11;
	// printf("%lld %lld %lld\n",x,t-11,y-t);
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
999999989 999999999999999989
4741671816274116608 4876203697187506176
*/