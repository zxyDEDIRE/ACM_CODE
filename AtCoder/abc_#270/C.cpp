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
const ull str_mod=212370440130137957ll;
const ull more=19260817;
const ull prime=233317;
const ull base=131;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
vector<int>v[maxn];
int dep[maxn];
int fa[maxn];
int n,s,t;
void dfs1(int x,int f,int deep)
{
	fa[x]=f;
	dep[x]=deep;
	for(auto y:v[x])
	{
		if(y==f)continue;
		dfs1(y,x,deep+1);
	}
}
vector<int>a,b;
void doit(int x,int y)
{
	while(x!=y)
	{
		if(dep[x]>=dep[y])a.push_back(x),x=fa[x];
		else b.push_back(y),y=fa[y];
	}
	for(auto i:a)
		cout<<i<<" ";
	cout<<x<<" ";
	reverse(b.begin(),b.end());
	for(auto i:b)
		cout<<i<<" ";
	cout<<endl;
}
void solve()
{
	cin>>n>>s>>t;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1,1,1);
	doit(s,t);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}