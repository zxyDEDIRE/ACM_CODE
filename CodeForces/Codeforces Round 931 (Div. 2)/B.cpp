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
void solve()
{
	ll n;
	cin>>n;
	ll ans=n;
	for(int a=0;a<=10;a++)
	{
		for(int b=0;a+b<=10;b++)
		{
			for(int c=0;a+b+c<=10;c++)
			{
				for(int d=0;a+b+c+d<=10;d++)
				{
					ll now=a+b*3+c*6+d*10;
					if(now<=n && (n-now)%15==0)
						ans=min(ans, a+b+c+d+(n-now)/15);
				}
			}
		}
	}

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