/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
// #define endl "\n"
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
vector<int>v[maxn];
bool vis[maxn];
int n,m;
int flag=0;
void in(){
	int k,x;
	cin>>k;
	while(k--)cin>>x;
}
void dfs(int x)
{
	if(flag)
		cout<<x<<endl;
	else flag=1;

	if(x==n){
		exit(0);
	}
	int k;
	cin>>k;
	vector<int>v;
	while(k--){
		int y;cin>>y;
		v.push_back(y);
	}
	reverse(v.begin(),v.end());
	for(auto y:v)
	{
		if(vis[y])continue;
		vis[y]=1;
		dfs(y);
		cout<<x<<endl;
		in();
		vis[y]=0;
	}
}
void solve()
{
	cin>>n>>m;
	vis[1]=1;
	dfs(1);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1 2
1 3
1 4 
1 5
1 6

*/