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
void solve()
{
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	struct node{
		int x,y;
		bool operator<(const node&a)const{
			if(y!=a.y)return y>a.y;
			return x<a.x;
		}
	};
	set<node>s;  
	s.insert({1,0});
	s.insert({2,1});
	auto x=*s.begin();
	cout<<x.x<<" "<<x.y<<endl;
		solve();
	return 0;
}