/*！*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
int n;
void solve()
{
	cin>>n;
	int t=9;
	int T=0;
	int s=1;
	int ans=0;
	while(1)
	{
		int now=min(n,t)-(t/10);
		ans+=now*s;

		if(t>n)break;
		t=t*10+9;
		s++;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("in.txt","r",stdin);
 // freopen("out.txt","w",stdout);
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
1000000000
*/