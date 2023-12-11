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
int dp[111][111];
int g[44][44];
int nxt[111];
char s[111];
int n,m,k;
void kmp()
{
	nxt[1]=0;
	for(int i=2;i<=m;i++)
	{
		nxt[i]=nxt[i-1];
		while(s[nxt[i]+1]!=s[i]&&nxt[i])
			nxt[i]=nxt[nxt[i]];
		if(s[nxt[i]+1]==s[i])nxt[i]++;
	}
	for(int i=0;i<m;i++)
	{
		for(int j='0';j<='9';j++) 
		{
			int tmp=i;
			while(tmp&&s[tmp+1]!=j)
				tmp=nxt[tmp];
			if(s[tmp+1]==j)tmp++;
			if(tmp<m)g[i][tmp]++;
		}
	}
}
void solve()
{
	cin>>n>>m>>k>>s+1;
	kmp();
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
			cout<<g[i][j]<<" \n"[j==m-1];
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=min(m-1,i);j++)
		{
			for(int k=0;k<=min(m-1,i-1);k++)
			{
				if(j==k)continue;
				dp[i][j]+=dp[i-1][k]*g[k][j];
			}
		}
	}
	// for(int j=0;j<m;j++)
		// cout<<dp[n][j]<<" ";cout<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}