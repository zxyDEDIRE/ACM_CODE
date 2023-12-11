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
ll d1,d2,x;
void solve()
{
	cin>>d1>>d2>>x;
	ll g=__gcd(d1,d2);

	ll x1=(x/g)*g;
	vector<ll>v;
	v.push_back(x1);
	for(int i=1;i<=10;i++)
		v.push_back(x1+g*i),v.push_back(x1-g*i);
	sort(v.begin(),v.end());
	ll mi=1e18,fl=0;
	for(auto i:v)
	{
		ll now=abs(i-x);
		if(now<mi)
		{
			mi=now;
			fl=i;
		}
	}
	cout<<fl<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}