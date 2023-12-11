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
vector<array<int,3>>v;
int n,m;
void dfs(int _x,int _y,int l,int r)
{
	if(l==r){
		v.push_back({_x,_y,l});
		return ;
	}
	else if(l<r)
	{
		v.push_back({_x,_y,l});
		dfs(_x,_y+l,l,r-l);
	}
	else
	{
		v.push_back({_x,_y,r});
		dfs(_x+r,_y,l-r,r);
	}
}
void solve()
{
	cin>>n>>m;
	v.clear();
	dfs(0,0,n,m);
	cout<<"YES\n";
	cout<<v.size()<<endl;
	for(auto [x,y,w]:v)
		cout<<x<<" "<<y<<" "<<w<<endl;

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