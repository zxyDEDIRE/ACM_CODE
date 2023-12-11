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
bool vis[maxn];
int nxt[maxn];
int dp[maxn];
int f[maxn];
string s,t;
int n,m;
void init(string &s)
{
	nxt[1]=0;
	int len=s.size()-1;
	for(int i=2;i<=len;i++)
	{
		nxt[i]=nxt[i-1];
		while(s[nxt[i]+1]!=s[i]&&nxt[i])
			nxt[i]=nxt[nxt[i]];
		if(s[nxt[i]+1]==s[i])nxt[i]++;
	}
}
void solve()
{
	cin>>s>>t;
	n=s.size();
	m=t.size();
	s=" "+s;
	t=" "+t;
	init(t);
	int now=m;
	vector<int>v;
	while(now){
		now=nxt[now];
		v.push_back(m-now);
	}
	// for(int i=0,j=0;i<n;i++)
	// {
	// 	while(j&&s[i+1]!='?'&&s[i+1]!=t[j+1])j=nxt[j];
	// 	if(s[i+1]=='?'||s[i+1]==t[j+1])j++;
	// 	vis[i+1]=j;
	// 	if(j==m){
	// 		j=nxt[j];
	// 	}
	// }
	for(int i=1;i+m-1<=n;i++)
	{
		int flag=1;
		for(int j=1;j<=m;j++)
			if(s[i+j-1]!='?'&&s[i+j-1]!=t[j]){
				flag=0;
				break;
			}
		if(flag)vis[i+m-1]=1;
	}
	vis[0]=1;
	for(int i=1;i<=n;i++)
	{
		dp[i]=max(dp[i],dp[i-1]);
		if(vis[i])
		{ 
			// dp[i]=max(dp[i],dp[i-m]+1);
			f[i]=dp[i-m]+1;
			for(auto y:v)
			{
				f[i]=max(f[i],f[i-y]+1);
				// if(vis[i-y])
				// 	dp[i]=max(dp[i],dp[i-y]+1);
			}
			dp[i]=max(dp[i],f[i]);
		}
	}
	for(int i=1;i<=n;i++)
		cout<<i<<" "<<dp[i]<<" "<<f[i]<<endl;
	cout<<dp[n]<<endl;
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
a?????a
ab
a????a
ab
a???a
ab
a??a
ab

abcabca
abca
*/