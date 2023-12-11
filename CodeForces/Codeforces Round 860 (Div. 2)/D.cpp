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
const int INF=1e9+7;
const int maxn=1e6+100;
int dp[maxn];
int sum[maxn];
int ans[maxn];
int p[maxn];
int n,MAX;
bool A()
{
	if(n==1)return 0;
	int l=1,r=n,now=1;
	if(abs(p[1])<=abs(p[n]))
		ans[1]=p[n],r--,sum[1]=max(0ll,p[n]);
	else ans[1]=p[1],l++,sum[1]=max(0ll,p[1]);

	while(l<r)
	{
		int fl=ans[now];
		int s=sum[now];
		if(s+p[r]<MAX)
			ans[now+1]=p[r],sum[now+1]=max(0ll,sum[now]+p[r]),now++,r--;
		else ans[now+1]=p[l],sum[now+1]=max(0ll,sum[now]+p[l]),now++,l++;
	}
	ans[now+=1]=p[l];

	sum[1]=ans[1];
	dp[1]=max(0ll,ans[1]);
	for(int i=2;i<=n;i++)
	{
		dp[i]=max(0ll,dp[i-1]+ans[i]);
		if(ans[i]==0)sum[i]=sum[i-1];
		else if(ans[i]<0)
		{
			if(ans[i-1]<=0)
				sum[i]=sum[i-1]+ans[i];
			else sum[i]=ans[i];
		}
		else if(ans[i]>0)
		{
			if(ans[i-1]>=0)
				sum[i]=sum[i-1]+ans[i];
			else sum[i]=ans[i];
		}
	}
	for(int i=1;i<=n;i++)
		if(abs(sum[i])>=MAX||dp[i]>=MAX){
			return 0;
		}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 1;
}
bool B()
{
	if(n==1)return 0;
	int l=1,r=n,now=1;
	if(abs(p[1])>=abs(p[n]))
		ans[1]=p[n],r--,sum[1]=max(0ll,p[n]);
	else ans[1]=p[1],l++,sum[1]=max(0ll,p[1]);
	while(l<r)
	{
		int fl=ans[now];
		int s=sum[now];

		if(s+p[r]<MAX)
			ans[now+1]=p[r],sum[now+1]=max(0ll,sum[now]+p[r]),now++,r--;
		else ans[now+1]=p[l],sum[now+1]=max(0ll,sum[now]+p[l]),now++,l++;
	}
	ans[now+=1]=p[l];

	
	sum[1]=ans[1];
	dp[1]=max(0ll,ans[1]);
	for(int i=2;i<=n;i++)
	{
		dp[i]=max(0ll,dp[i-1]+ans[i]);
		if(ans[i]==0)
			sum[i]=sum[i-1];
		else if(ans[i]<0)
		{
			if(ans[i-1]<=0)
				sum[i]=sum[i-1]+ans[i];
			else sum[i]=ans[i];
		}
		else if(ans[i]>0)
		{
			if(ans[i-1]>=0)
				sum[i]=sum[i-1]+ans[i];
			else sum[i]=ans[i];
		}
	}
	for(int i=1;i<=n;i++)
		if(abs(sum[i])>=MAX||dp[i]>=MAX){
			return 0;
		}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 1;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		ans[i]=sum[i]=0;
	}
	sort(p+1,p+1+n);
	MAX=p[n]-p[1];

	if(!B())cout<<"NO"<<endl;
	
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
/*
7
-18 13 -18 -17 12 15 13

33

-18 15 13 -18 13 12 -17


YES
-18 15 13 -18 13 -18 12
*/