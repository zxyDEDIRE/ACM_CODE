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
bitset<32>a;
ll x;
void solve()
{
	cin>>x;
	a=x;
	vector<int>v[4];
	for(int i=0;i<32;i++){
		v[i/8].push_back(a[i]);
	}
	vector<int>p(4);
	for(int i=0;i<4;i++)
		p[i]=i;
	ll ans=0;
	do{
		vector<int>q;
		for(int i=0;i<4;i++)
			for(auto j:v[p[i]])
				q.push_back(j);
		ll now=0;
		for(int i=0;i<32;i++)
			if(q[i])now|=(1ll<<i);
		ans=max(ans,now);
	}while(next_permutation(p.begin(),p.end()));
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}