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
vector<pii>v[maxn];
bool vis[maxn];
int dis[maxn];
int k;
void solve()
{
	cin>>k;
	for(int i=0;i<k;i++)
		dis[i]=INF;
	dis[2]=2;
	deque<int>q;
	q.push_back(2);
	while(!q.empty())
	{
		int x=q.front();q.pop_front();
		if(dis[x*10%k]>dis[x])
			q.push_front(x*10%k),dis[x*10%k]=dis[x];
		if(dis[(x+1)%k]>dis[x]+1)
			q.push_back((x+1)%k),dis[(x+1)%k]=dis[x]+1;
	}
	cout<<dis[0]<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}