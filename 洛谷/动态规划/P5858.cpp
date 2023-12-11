/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e18+7;
const int maxn=6e3+100;
int pre[maxn];
int dp[maxn];
int q[maxn];
int p[maxn];
int n,w,s;
void solve()
{
	cin>>n>>w>>s;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int j=0;j<=w;j++)
		dp[j]=pre[j]-INF;
	dp[1]=0;
	for(int i=1;i<=n;i++)
	{
		memcpy(pre,dp,sizeof(dp));
		int head=0,tail=-1;
		for(int j=min(w,i);j>=1;j--)
		{
			if(head<=tail&&q[head]-j>=s)head++;
			while(head<=tail&&pre[q[tail]]<pre[j])
				tail--;
			dp[j]=max(pre[j],pre[j-1])+j*p[i];
			if(head<=tail)
				dp[j]=max(dp[j],pre[q[head]]+j*p[i]);
			q[++tail]=j;
		}
		// cout<<"DP ";
		// for(int j=1;j<=w;j++)
		// 	cout<<dp[j]<<" ";
		// cout<<endl;
	}
	int ma=-INF;
	for(int i=1;i<=w;i++){
		ma=max(ma,dp[i]);
		// cout<<dp[i]<<" ";
	}
	cout<<ma<<endl;
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