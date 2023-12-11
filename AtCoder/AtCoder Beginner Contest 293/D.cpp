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
int n,m,flag;
void dfs(int x,int fa)
{
	if(vis[x]){
		flag=1;
		return ;
	}
	vis[x]=1;
	for(auto y:v[x])
		if(y!=fa)
			dfs(y,x);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		v[i].push_back(i+n);
		v[i+n].push_back(i);
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		char a,b;
		cin>>x>>a>>y>>b;
		if(a=='R')x+=n;
		if(b=='R')y+=n;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int cnt_a=0,cnt_b=0;
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			flag=0;
			dfs(i,0);
			if(flag)cnt_a++;
			else cnt_b++;
		}
	cout<<cnt_a<<" "<<cnt_b<<endl;
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