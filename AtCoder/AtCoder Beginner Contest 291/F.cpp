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
vector<int>G[maxn];
string mp[maxn];
bitset<maxn>vis;
int dis_a[maxn];
int dis_b[maxn];
int ans[maxn];
int n,m;
void dij(int s,int* dis,vector<int>*v)
{
	for(int i=1;i<=n;i++)
		dis[i]=INF,vis[i]=0;
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
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		ans[i]=INF;
		cin>>mp[i];
		for(int j=0;j<m;j++)
		{
			if(mp[i][j]=='1')
			{
				G[i].push_back(i+j+1);
				v[i+j+1].push_back(i);
			}

		}
	}
	dij(1,dis_a,G);
	dij(n,dis_b,v);
	for(int i=1;i<=n;i++)
		cout<<dis_a[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<dis_b[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++)
	{
		multiset<int>s;
		for(int j=0;j<m;j++)
			if(mp[i][j]=='1')
				s.insert(dis_a[i]+dis_b[i+j+1]+1);
		for(int j=0;j<m;j++)
		{
			if(mp[i][j]=='0')
			{
				ans[i+j+1]=min(ans[i+j+1],*s.begin());
				continue;
			}
			s.erase(s.find(dis_a[i]+dis_b[i+j+1]+1));
			ans[i+j+1]=min(ans[i+j+1],*s.begin());
			s.insert(dis_a[i]+dis_b[i+j+1]+1);
		}
	}
	for(int i=2;i<n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
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
/*
1->2 1->4
2->5
3->4 3->6
5->6

*/