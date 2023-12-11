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
const int N=5e3+10;
int vis[N][N];
int dp[N][N];
string s;
int n;
void solve()
{
	cin>>s;
	n=s.size();
	s=" "+s;
	for(int len=1;len<=n;len++)
	{
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			if(j==i)vis[i][j]=1;
			else if(j==i+1&&s[i]==s[j])vis[i][j]=1;
			else
			{
				if(vis[i+1][j-1]&&s[i]==s[j])vis[i][j]=1;
			}
		}
	}
	for(int j=1;j<=n;j++)
		for(int i=n;i>=1;i--)
			vis[i][j]+=vis[i+1][j];

	for(int i=1;i<=n;i++)
	{
		dp[i][i]=1;
		for(int j=i+1;j<=n;j++)
		{
			int cnt=vis[i][j]-vis[j+1][j];
			dp[i][j]=dp[i][j-1]+cnt;
		}
	}
	int q;cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]<<endl;
	}

}
/*
a
a aa
a aa aaa
caaa
1 4

00101
22211
*/
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
 // fclose(stdout);
	return 0;
}