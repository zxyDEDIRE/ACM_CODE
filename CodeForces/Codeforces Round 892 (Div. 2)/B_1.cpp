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
struct node{
	int x,y;
};
vector<node>p;
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int m;cin>>m;
		while(m--){
			int x;cin>>x;
			p.push_back({x,i});
		}
	}
	sort(p.begin(),p.end(),[&](node a,node b){
		return a.x<b.x;
	});
	for(auto [x,y]:p)
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
/*
              2 3
5 1
       6 2
7 1
       8 2
              9 3
       11 2
1001 1
1007 1

1
2
2
1 5
1
4

2
4
1 2 4 5
1
3
*/