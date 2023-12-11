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
int n,k,x;
void solve()
{
	cin>>n>>k>>x;
	if(n<k||x<k-1){
		cout<<-1<<endl;
		return ;
	}
	ll ans=0;
	k--;
	ans+=(1+k)*k/2;
	if(x!=k+1  )ans+=(n-k-1)*x;
	else ans+=(n-k-1)*k;
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*

0 1 2
2 2
*/