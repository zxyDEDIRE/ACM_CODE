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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());//ull  大概率生成不相同数据
ll getRand(ll l,ll r){
    uniform_int_distribution < ll > uid(l,r);
    return uid(rng);
}
void solve()
{
	int n=10;
	set<pii>s;
	s.insert({5,5});
	int num=getRand(4,40);
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
https://hr.nowcoder.com/
CCSU2019@nowcoder.com
ccsu2024fight
*/