#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e18+7;
const int maxn=1e6+100;
vector<int>v[maxn];
bitset<maxn>vis;
int dis_1[maxn];
int dis_2[maxn];
int dis_3[maxn];
int w_1,w_2,w_3;
int s_1,s_2;
int n,m;
void bfs(int s,int dis[],int w)
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	queue<int>q;
	q.push(s);
	dis[s]=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(auto y:v[x])
		{
			if(dis[y]>dis[x]+w)
			{
				dis[y]=dis[x]+w;
				q.push(y);
			}
		}
	}
}
void solve()
{
	cin>>w_1>>w_2>>w_3>>s_1>>s_2>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs(s_1,dis_1,w_1);
	bfs(s_2,dis_2,w_2);
	bfs(n,dis_3,w_1+w_2-w_3);
	int mi=INF;
	for(int i=1;i<=n;i++)
		mi=min(mi,dis_1[i]+dis_2[i]+dis_3[i]);
	// cout<<mi<<endl;/
	if(mi==INF)cout<<-1<<endl;
	else cout<<mi<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}