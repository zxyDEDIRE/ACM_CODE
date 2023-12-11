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
const int N=5050;
vector<int>v[N];
int mp[501][N];
bitset<N>t[N];
ll dp[maxn];
int in[maxn];
ll w[maxn];
int n,m;
void solve()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		dp[i]=0;v[i].clear();in[i]=0;
		t[i].set();
	}
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)
			cin>>mp[j][i];

	for(int i=1;i<=m;i++)
	{
		vector<pii>v(n);
		for(int j=1;j<=n;j++)
			v[j-1]={j,mp[i][j]};
		sort(v.begin(),v.end(),[&](pii a,pii b){return a.second<b.second;});
		bitset<N>now;
		int l=0;
		for(int j=0;j<n;j++)
		{
			if(v[l].second!=v[j].second)
			{
				while(l<j)
				{
					now[v[l].first]=1;
					l++;
				}
			}
			t[v[j].first]&=now;
		}
	}

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(t[j][i]){
				// cout<<i<<" "<<j<<endl;
				v[j].push_back(i);
				in[i]++;
			}

	queue<int>q;
	for(int i=1;i<=n;i++)
		if(!in[i])q.push(i);
	ll ans=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		dp[x]+=w[x];
		ans=max(ans,dp[x]);
		for(auto y:v[x])
		{
			dp[y]=max(dp[y],dp[x]);
			in[y]--;
			if(!in[y])q.push(y);
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
1 2 3 4 5
1 3 4 5 2
5 1 2 3 4


*/