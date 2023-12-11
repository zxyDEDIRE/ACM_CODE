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
using B=bitset<100>;
bitset<100>a,b;
void solve()
{
	ll x,y;
	cin>>x>>y;
	a=B(x);
	b=B(y);
	int ma=0,mb=0;
	for(int i=0;i<100;i++)
	{
		if(a[i])ma=max(ma,i);
		if(b[i])mb=max(mb,i);
	}
	vector<ll>v;
	ll now=0;
	for(int i=mb-1;i>=0;i--)
		if(a[i]!=b[i])
			now|=(1ll<<i);

	v.push_back(now);
	if(a[mb]!=b[mb])
		v.push_back((1ll<<mb));


	now=0;
	for(int i=ma;i>mb;i--)
		if(a[i]!=b[i])
			now|=(1ll<<i);

	v.push_back(now);
	cout<<v.size()<<endl;
	for(auto i:v)
		cout<<i<<" ";cout<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
1111
  11
110
 10
*/