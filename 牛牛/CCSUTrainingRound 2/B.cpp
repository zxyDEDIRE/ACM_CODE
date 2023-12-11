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
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
vector<int>v[maxn];
bitset<maxn>vis_a;
bitset<maxn>vis_b;
bitset<maxn>vis;
int dis[maxn];
int n,m,num_a,num_b;
void bfs(int s,int t)
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	vis.reset();
	dis[s]=0;
	priority_queue<node>q;
	q.push({s,0});
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
}
void solve()
{
	cin>>n>>m>>num_a>>num_b;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs(1,n);
	for(int i=1;i<=n;i++)
		if(dis[i]<=num_a)vis_a[i]=1,cout<<i<<" ";
	cout<<endl;
	bfs(n,1);
	for(int i=1;i<=n;i++)
		if(dis[i]<=num_b)vis_b[i]=1,cout<<i<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++)
		if(vis_a[i]==1&&vis_b[i]==1){
			cout<<"YES"<<endl;
			return ;
		}
	cout<<"NO"<<endl;

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