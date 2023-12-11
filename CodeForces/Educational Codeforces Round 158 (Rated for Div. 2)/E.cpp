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
const ll INF=1e18+7;
const int maxn=1e6+100;
vector<int>v[maxn];
bitset<maxn>ok;
bool vis[maxn];
int in[maxn];
ll w[maxn];
int n;
void init(){
	for(int i=1;i<=n;i++)
	{
		v[i].clear();
		vis[i]=0;
		in[i]=0;
	}
}
ll bfs(int x,int fa,ll W)
{
	queue<int>q;
	ok.reset();
	ll sum=0;
	q.push(x);
	ok[fa]=1;
	ok[x]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		sum+=x;
		if(sum+W>0)return INF;
		for(auto y:v[x])
		{
			if(!ok[y]&&!vis[y])
			{
				ok[y]=1;
				q.push(y);
			}
		}
	}
	return sum;
}
void solve()
{
	cin>>n;
	init();
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		sum+=w[i];
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
		in[x]++;
		in[y]++;
	}
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(in[i]==1)
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(w[x]>0)continue;
		sum-=w[x];
		vis[x]=1;
		in[x]=0;
		for(auto y:v[x])
			if(!vis[y]){
				in[y]--;
				if(in[y]==1)
					q.push(y);
			}
	}
	vector<int>now;
	for(int i=1;i<=n;i++)
		if(in[i]==2)
			now.push_back(i);
	for(auto x:now)
	{
		vector<int>p;
		for(auto y:v[x])
			if(vis[y])
				p.push_back(w[y]);
		sort(p.begin(),p.end());
		if(p.size() && p[0]+w[x]>0){
			sum+=p[0];
		}
	}
	now.clear();
	for(int i=1;i<=n;i++)
		if(!vis[i]&&w[i]<0)
			now.push_back(i);
	for(auto x:now)
	{
		vector<int>p;
		for(auto y:v[x])
		{
			ll _w=bfs(y,x,w[x]);
			p.push_back(_w);
		}
		sort(p.begin(),p.end(),[&](ll a,ll b){
			return a>b;
		});
		ll tot=0;
		for(int i=2;i<p.size();i++)
			tot+=p[i];
		
	}

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
4
1 2 0 1
1 1
  1 0 1
删掉负数两种情况：
1.in==1
2.删至剩余两颗子树
*/