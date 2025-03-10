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
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
int S[maxn],K[maxn],R[maxn];
vector<int>v[maxn];
bool vis[maxn];
int ans[maxn];
int dp[maxn];
int n;
void solve()
{
	cin>>n;
	priority_queue<node>q;
	for(int i=1;i<=n;i++)
	{
		cin>>S[i]>>K[i]>>R[i];
		for(int j=1,x;j<=R[i];j++){
			cin>>x;
			v[x].push_back(i);
		}
		dp[i]=S[i];
		q.push({i,K[i]});
	}
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		ans[x]=DIS;
		for(auto y:v[x])
		{
			if(vis[y]||dp[y]>K[y])continue;
			dp[y]+=ans[x];
			R[y]--;
			if(!R[y])
				q.push({y,dp[y]});
		}
	}
	cout<<ans[1]<<endl;

}	
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}