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
vector<int>v[maxn];
bool vis[maxn];
int dis[maxn];
int n,tot;
void solve()
{
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		if(!mp.count(x))mp[x]=++tot;
		if(!mp.count(y))mp[y]=++tot;
		v[mp[x]].push_back(y);
		v[mp[y]].push_back(x);
	}
	queue<int>q;
	q.push(1);
	int ans=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		ans=max(ans,x);
		x=mp[x];
		if(vis[x])continue;
		vis[x]=1;
		for(auto y:v[x])
			q.push(y);
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