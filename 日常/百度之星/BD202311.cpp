#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[maxn];
int dis[maxn];
int a[maxn];
int n;
void bfs(int s,int t)
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	dis[s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(auto y:v[x])
		{
			if(dis[y]>dis[x]+1)
			{
				dis[y]=dis[x]+1;
				q.push(y);
			}
		}
	}
	cout<<dis[t]<<endl;
}
void solve()
{
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(mp.count(a[i]))
			v[mp[a[i]]].push_back(i);
		mp[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(i+1<=n)v[i].push_back({i+1});
		if(i-1>=1)v[i].push_back({i-1});
	}
	bfs(1,n);
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}