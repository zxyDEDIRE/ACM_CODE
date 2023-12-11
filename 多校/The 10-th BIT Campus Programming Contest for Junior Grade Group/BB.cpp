/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int dp[11100];
int p[maxn];
int n,sum=0;
void NO(){cout<<"NO"<<endl;}
void YES(){cout<<"YES"<<endl;}
void solve()
{
	cin>>n;
	sum=0;
	for(int i=1;i<=n;i++)
		cin>>p[i],sum+=p[i];
	if(sum&1)return NO();
	for(int i=0;i<=sum/3;i++)
		dp[i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=sum/3;j>=0;j--)
		{
			if(j>=p[i])
				dp[j]=max(dp[j],dp[j-p[i]]+p[i]);
		}
	}
	if(dp[sum/3]!=sum/3)return NO();

	for(int i=0;i<=sum/3*2;i++)
		dp[i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=sum/3*2;j>=0;j--)
		{
			if(j>=p[i])
				dp[j]=max(dp[j],dp[j-p[i]]+p[i]);
		}
	}
	if(dp[sum/3*2]==sum/3*2)return YES();
	else return NO();
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3 3
*/