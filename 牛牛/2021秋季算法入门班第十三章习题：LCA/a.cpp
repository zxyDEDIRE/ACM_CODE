/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
vector<int>v[maxn];
int f[maxn][25];
int dep[maxn];
int n,q,s,t;
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=0;i<=20;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(auto y:v[x])
		if(y!=fa)
			dfs(y,x);
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
		for(int i=20;i>=0;i--)
			if(dep[f[x][i]]>=dep[y])
				x=f[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;i--)
		if(dep[f[x][i]]!=dep[f[y][i]])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
int dis(int x,int y)
{
	int a=LCA(x,y);
	return dep[x]+dep[y]-dep[a]*2;
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cin>>s>>t;
	dfs(1,0);
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<min({dis(x,y),dis(x,s)+dis(t,y),dis(x,t)+dis(s,y)})<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
11
1 2
2 3
3 8
2 4
4 9
1 5
5 6
5 7
6 10
10 11
8 11
1
4 6
*/