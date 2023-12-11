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
int p[maxn];
int n;
void solve()
{
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
		cin>>p[i],mp[p[i]]++;
	if(n<=2||mp.size()==1){
		cout<<"Yes\n";
		return ;
	}
	if(mp.size()==2)
	{
		vector<int>v;
		for(auto [x,y]:mp)
			v.push_back(y);
		if(abs(v[0]-v[1])<=1){
			cout<<"Yes\n";
			return ;
		}
	}
	cout<<"No\n";
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