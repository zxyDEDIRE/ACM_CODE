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
int vis[maxn];
int p[maxn];
int n,flag=0;
void dfs(int x)
{
	if(x==n+1){
		for(int i=1;i<=n;i++)
			cout<<p[i]<<" ";
		cout<<endl;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		if(abs(x-i)<2||abs(x-i)>3)continue;
		p[x]=i;
		vis[i]=1;
		dfs(x+1);
		vis[i]=0;
	}
}
void solve()
{
	cin>>n;
	dfs(1);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}