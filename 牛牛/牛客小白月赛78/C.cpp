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
ll a,b,k;
void solve()
{
	cin>>k>>a>>b;
	set<ll>s;
	s.insert(a);
	s.insert(b);
	for(int i=1;i<=k;i++)
	{
		ll x=*s.begin();
		s.insert(x+a);
		s.insert(x+b);
		while(s.size()>k*2)
		{
			s.erase(*s.rbegin());
		}
	}
	while(s.size()>k)
	{
		s.erase(*s.rbegin());
	}
	cout<<*s.rbegin()<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}