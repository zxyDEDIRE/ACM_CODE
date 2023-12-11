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
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
vector<int>v[maxn];
bitset<maxn>vis;
int dis[maxn];
int num[maxn];
int p[maxn];
int n,m,k;
void dij(int s)
{
	memset(dis+1,INF,sizeof(int)*n);
	priority_queue<node>q;
	q.push({s,0});
	dis[s]=0;
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto y:v[x])
		{
			if(dis[y]>dis[x]+1)
			{
				dis[y]=dis[x]+1;
				q.push({y,dis[y]});
			}
		}
	}
	num[s]=0;
	queue<int>Q;
	Q.push(s);
	vis.reset();
	while(!Q.empty())
	{
		int x=Q.front();Q.pop();
		num[x]++;
		if(vis[x])continue;
		vis[x]=1;
		for(auto y:v[x])
		{
			if(dis[y]==dis[x]+1)
				Q.push(y);
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[y].push_back(x);
	}
	cin>>k;
	for(int i=1;i<=k;i++)
		cin>>p[i];
	int s=p[1],t=p[k];
	dij(t);
	int ans_a=0,ans_b=0;
	// for(int i=1;i<=n;i++)
	// 	cout<<num[i]<<" ";
	// cout<<endl;
	for(int i=1;i<k;i++)
	{
		int x=p[i];
		int y=p[i+1];
		if(dis[y]!=dis[x]-1)ans_a++,ans_b++;
		else if(num[x]>1)ans_b++;
	}
	cout<<ans_a<<" "<<ans_b<<endl;
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