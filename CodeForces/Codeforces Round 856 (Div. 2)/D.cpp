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
vector<int>v[maxn];
bitset<maxn>vis;
int val[maxn];
int w[maxn];
int n,m;
void dfs(int x,int c){
	vis[x]=1;
	val[x]+=c;
	for(auto y:v[x])
		if(!vis[y])
			dfs(y,c);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int s,x,y,c;
		cin>>s>>x>>y>>c;
		v[s].push_back(x);
		v[s].push_back(y);
		w[s]=c;
	}
	for(int i=0;i<=n+1;i++){
		vis.reset();
		dfs(i,w[i]);
	}
	int cnt=0;
	for(int i=2;i<=n;i++)
		if(val[i]>=m){
			cout<<i<<" "<<val[i]<<endl;
			cnt++;
		}
	cout<<cnt<<endl;
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