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
ll a[maxn];
ll b[maxn];
ll n,x,y;
void solve()
{
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++)
	{
		int _x;
		cin>>_x;
		a[i]=_x%x;
		b[i]=_x%y;
	}

	map<int,int>mp;
	int _id=0;
	vector<vector<int>>v;
	for(int i=1;i<=n;i++)
	{
		if(!mp.count(b[i]))
		{
			mp[b[i]]=_id++;
			v.push_back(vector<int>());
		}
		v[mp[b[i]]].push_back(i);
	}
	ll ans=0;
	for(auto p:v)
	{
		map<int,int>mp;
		for(auto i:p)
		{
			int ned=(x-a[i]+x)%x;
			ans+=mp[ned];
			mp[a[i]]++;
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
/*
a+b=Tx
a-b=Sy
2a=Tx+Sy
2b=Tx-Sy


*/