#include <ext/pb_ds/assoc_container.hpp>
#include<bits/stdc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
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

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> Tree;
Tree t;

template<typename T>
int getRank(T x)
{
	return t.order_of_key(x)+1;
}

template<typename T>
T getVal(int k)
{
	auto it=t.find_by_order(k-1);
	if(it!=t.end())
		return *it;
	else
		return {INF,0};
}


int n,m;
void solve()
{
	cin>>n>>m;
	
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}