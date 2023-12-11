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
ll n,m;
void solve()
{
	cin>>n>>m;
	vector<int>v;
	int x=m;
	while(x!=1){
		v.push_back(x);
		x=ceil(x*0.5);
	}v.push_back(1);
	ll sum=0;
	for(int i=0;i<v.size();i++)
	{
		sum+=v[i];
		if(sum>=n){
			cout<<i<<endl;
			return ;
		}
	}
	n-=sum;
	ll ans=n+v.size()-1;
	cout<<ans<<endl;
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