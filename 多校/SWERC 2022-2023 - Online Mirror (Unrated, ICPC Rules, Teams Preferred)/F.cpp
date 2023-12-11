/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<pii>v[maxn];
int vis[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		v[i].clear();
	for(int i=1;i<=m;i++)
	{
		vis[i]=0;
		int x,y;
		cin>>x>>y;
		v[x].push_back({y,i});
		v[y].push_back({x,i});
	}
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(v[i].size()==n-1)continue;
		for(auto [a,x]:v[i]){
			vis[x]=1;
		}
		flag=1;
		break;
	}
	if(flag){
		cout<<2<<endl;
		for(int i=1;i<=m;i++)
			if(vis[i])cout<<1<<" ";
			else cout<<2<<" ";
		cout<<endl;
	}
	else
	{
		for(auto [a,x]:v[1])
			vis[x]=1;
		vis[v[1].back().second]=2;
		cout<<3<<endl;
		for(int i=1;i<=m;i++)
			if(vis[i])cout<<vis[i]<<" ";
			else cout<<3<<" ";
		cout<<endl;
	}

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1 2
1 3

1 4

2 3
2 4
3 4

*/
/*
7 18
3 6
2 7
1 3
2 4
4 5
1 7
6 2
4 7
5 1
5 2
2 3
6 4
5 6
2 1
3 4
5 7
6 1
7 3
2
2 2 1 2 2 1 2 1 1 1 2 2 2 1 1 2 1 1
*/