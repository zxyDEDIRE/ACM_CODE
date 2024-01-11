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
const int maxn=1e6+1;
void f(int x,map<int,int>&mp)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0){
			while(x%i==0){
				mp[i]++;
				x/=i;
			}
		}
	if(x!=1)mp[x]++;
}
void solve()
{
	int x,y;
	cin>>x>>y;
	map<int,int>mpa,mpb;
	f(x,mpa);
	f(y,mpb);
	for(auto [_a,_b]:mpa)
		if(_b>mpb[_a]){
			cout<<-1<<endl;
			return ;
		}
	cout<<x<<" "<<y<<endl;
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