/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
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
const int N=5e3+100;
int dp[N][N];
char s[maxn];
int n,ans;
void solve()
{
	cin>>s+1;
	n=strlen(s+1);
	for(int len=2;len<=n;len++)
	{
		for(int i=1;i+len-1<=n;i++)
		{
			int fl=0;
			if(s[i]>s[i+len-1])ans++,dp[i][i+len-1]=1;//,cout<<i<<" "<<i+len-1<<endl;
			if(s[i]==s[i+len-1]&&dp[i+1][i+len-2])ans++,dp[i][i+len-1]=1;//,cout<<i<<" "<<i+len-1<<endl;
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
210102
1 2
2 3
4 5
1 3
1 4
1 5

*/