/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
vector<int>v[maxn];
bitset<maxn>vis;
int dis[maxn];
int dp[maxn];
int in[maxn];
int n,k;
void solve()
{
	cin>>n>>k;
	vis.reset();
	for(int i=1;i<=n;i++)
		cin>>dis[i],v[i].clear(),dp[i]=0;
	for(int i=1;i<=k;i++){
		int x;cin>>x;
		dis[x]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int m;
		cin>>m;
		if(m==0)dp[i]=dis[i];
		while(m--)
		{
			int x;cin>>x;
			v[x].push_back(i);
			in[i]++;
		}
	}
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		dis[x]=min(dis[x],dp[x]);
		for(auto y:v[x])
		{
			dp[y]+=dis[x];
			in[y]--;
			if(!in[y])q.push(y);			
		}
	}
	for(int i=1;i<=n;i++)
		cout<<dis[i]<<" ";cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}