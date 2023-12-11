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
double dp[maxn];
int a[maxn];
int n;
void A()
{
	auto check=[&](double mid)->bool{
		for(int i=1;i<=n;i++){
			dp[i]=dp[i-1]+(1.0*(a[i]-mid));
			if(i>=2)
				dp[i]=max(dp[i],dp[i-2]+(1.0*(a[i]-mid)));
		}
		if(max(dp[n],dp[n-1])>0)return 1;
		return 0;
	};
	double l=1,r=1e9+5,ans=l;
	while(l<r-0.00001)
	{
		double mid=0.5*(l+r);
		if(check(mid))l=mid,ans=mid;
		else r=mid;
	}
	printf("%.4lf\n",ans);
}
void B()
{
	int l=1,r=1e9+5,ans=l;
	auto check=[&](int mid)->bool{
		dp[0]=0;
		for(int i=1;i<=n;i++)
		{
			dp[i]=dp[i-1]+(a[i]>=mid?1:-1);
			if(i>1)
				dp[i]=max(dp[i],dp[i-2]+(a[i]>=mid?1:-1));
		}
		if(max(dp[n],dp[n-1])>0)return 1;
		return 0;
	};
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid;
		else r=mid;
	}
	while(check(ans+1))ans++;
	printf("%d\n",ans);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	A();
	B();
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}