/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
set<int>s[maxn];
int vis[maxn];
int in[maxn];
int n,m;
int flag;
void dfs(int x,int op)
{
	if(flag)return ;
	vis[x]=op;
	// cout<<"top "<<x<<" "<<vis[x]<<endl;
	for(auto y:v[x])
	{
		if(vis[y]&&vis[y]==vis[x]){
			// cout<<"zheli "<<y<<" "<<vis[y]<<endl;
			flag=1;
			// cout<<flag<<endl;
		}
		else if(!vis[y])
		{
			dfs(y,op^1);
		}
	}
}
void solve()
{
	cin>>n>>m;
	if(n<=895)
	{
		for(int i=1;i<=n;i++)
			v[i].clear(),vis[i]=0,s[i].clear();
	}
	
	for(int i=1;i<=m;i++)
	{
		int x,y;
		
		cin>>x>>y;
		if(n<=895)
		{
			s[x].insert(y);
			s[y].insert(x);
		}
	}
	if(n>895){
		cout<<"YES"<<endl;
		return ;
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(!s[i].count(j)&&i!=j)
				v[i].push_back(j);
	flag=0;
	// cout<<endl;
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			dfs(i,2);
			if(flag){
				cout<<"YES"<<endl;
				return ;
			}
		}
	cout<<"NO"<<endl;



}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}