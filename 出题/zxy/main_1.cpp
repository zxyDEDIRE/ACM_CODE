#include <ext/pb_ds/assoc_container.hpp>
#include<bits/stdc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
#define endl "\n"
using pii=pair<int,int>;
const int INF=1e9+7;

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
int get(int x){
    auto v=getVal<pii>(x);
    return v.first;
}


void solve()
{
	int n,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		t.insert({x,i});
		int mid_l = ceil(1.0*i/3);
		int mid_r = ceil(2.0*i/3);
        cout<<get(mid_l)<<" "<<get(mid_r)<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}