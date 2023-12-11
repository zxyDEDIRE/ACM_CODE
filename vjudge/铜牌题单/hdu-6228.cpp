/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
vector<int>v[maxn];
int siz[maxn];
int n,k,tot;
void dfs1(int x,int fa)
{
	siz[x]=1;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs1(y,x);
		siz[x]+=siz[y];
	}
}
void dfs(int x,int fa)
{
	for(auto y:v[x])
	{
		if(y==fa)continue;
		int a=siz[y];
		int b=n-a;
		if(a>=k&&b>=k)tot++;
		dfs(y,x);
	}
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		v[i].clear();
	for(int i=1;i<n;i++)
	{
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1,1);
	tot=0;
	dfs(1,1);
	cout<<tot<<endl;
}
signed main(){
 // freopen("C:\Users\tob\Desktop\P4391_9.in.txt","r",stdin);
 // freopen("C:\Users\tob\Desktop\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}