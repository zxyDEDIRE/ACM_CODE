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
const int N=5555;
bool dp[N][N];
int mp[N][N];
int ma[N];
int p[N];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++)
			mp[i][j]=INF,dp[i][j]=0;
	for(int i=1;i<=n;i++)
	{
		set<int>s;
		int top=0;
		for(int j=i;j<=n;j++)
		{
			s.insert(p[j]);
			while(s.count(top))top++;
			mp[i][top]=min(mp[i][top],j);
		}
		ma[i]=top;
	}
	// for(int i=1;i<=n;i++)
	// {
	// 	cout<<"I:"<<i<<" ";
	// 	for(int j=0;j<=n;j++)
	// 		cout<<j<<":"<<mp[i][j]<<" ";
	// 	cout<<endl;
	// }

	dp[0][0]=1;
	vector<int>v[N];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			for(int k=0;k<=ma[i];k++)
			{
				if(mp[i][k]==INF)continue;
				if(!dp[i-1][j])continue;
				dp[mp[i][k]][k^j]|=dp[i-1][j];
			}
			dp[i][j]|=dp[i-1][j];
		}
	}
	for(int i=n;i>=0;i--)
		if(dp[n][i]){
			cout<<i<<endl;
			return ;
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