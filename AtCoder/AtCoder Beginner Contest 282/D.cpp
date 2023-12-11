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
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[maxn],a,b;
map<pii,bool>mp;
bitset<maxn>vis;
int p[maxn];
int n,m,flag;
void dfs(int x,int t)
{
	if(flag)return ;
	p[x]=t;
	vis[x]=1;
	if(p[x]==2)a.push_back(x);
	else b.push_back(x);
	for(auto y:v[x])
	{
		if(vis[y])
		{
			if(p[y]!=(t^1))flag=1;
		}
		else if(vis[y]==0)dfs(y,t^1);
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	ll ans=0;
	ll sum=0;
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			a.clear();
			b.clear();
			dfs(i,2);
			for(auto x:a)
				ans+=(ll)(b.size())-(ll)(v[x].size());
			ll x=a.size(),y=b.size();
			ans+=1ll*sum*(x+y);
			sum+=(x+y);
		}
	if(flag){
		cout<<0<<endl;
		return ;
	}
	cout<<ans<<endl;
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
/*
6 4
1 2
2 3
4 5
5 6
*/