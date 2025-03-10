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
bool vis[maxn];
vector<int>ans;
stack<int>s;
int n,m;
void dfs(int x)
{
	s.push(x);
	vis[x]=1;
	if(v[x].size())
		dfs(v[x][0]);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x;cin>>x;
		v[x].push_back(x+1);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			dfs(i);
			while(s.size())
				ans.push_back(s.top()),s.pop();
		}
	for(auto i:ans)
		cout<<i<<" ";
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}