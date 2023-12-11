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
ll n;
vector<int>f(int x){
	vector<int>p;
	while(x){
		p.push_back(x%2);
		x/=2;
	}
	return p;
}
void solve()
{
	cin>>n;
	auto a=f(n);
	vector<int>ans(1,n);
	for(int i=0;i<a.size()-1;i++)
		if(a[i]){
			ans.push_back(n-=(1ll<<i));
		}
	while(n!=1)
		ans.push_back(n/=2);
	cout<<ans.size()<<endl;
	for(auto i:ans)
		cout<<i<<" ";cout<<endl;
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
112 16
*/