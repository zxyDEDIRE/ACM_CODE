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
vector<int>v[maxn];
ll in[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		in[x]++;
		in[y]++;
	}
	vector<ll>v;
	map<ll,ll>mp;
	for(int i=1;i<=n;i++)
		mp[in[i]]++;
	for(auto [x,y]:mp)
		v.push_back(x);

	// cout<<endl;for(int i=1;i<=n;i++)cout<<in[i]<<" ";cout<<endl;
	// cout<<endl;

	ll ans=0;
	for(int i=0;i<v.size();i++)
	{
		for(int j=i+1;j<v.size();j++)
		{
			ll now=1ll*((v[j]|v[i])*(v[j]&v[i]))%mod*(v[j]^v[i])%mod;
			now=((now%mod*mp[v[i]])%mod*mp[v[j]])%mod;
			(ans+=now)%=mod;
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	// int a,b;
	// cin>>a>>b;
	// int t=(a^b)*(a|b)*(a&b);
	// bitset<10>u(t);
	// cout<<u<<endl;
	// cout<<(a^b)<<" "<<(a&b)<<endl;
	// cout<<(a^b)*(a|b)*(a&b)<<endl;
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
6 6
2 5 6 9 18 12
*/