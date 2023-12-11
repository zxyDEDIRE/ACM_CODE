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
int dp[maxn];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	int ma=0;
	for(int i=1;i<=n;i++)
		cin>>p[i],ma=max(ma,p[i]);
	for(int i=0;i<=ma;i++)
		dp[i]=-1;
	sort(p+1,p+1+n);
	if(p[1]!=1){
		cout<<"NO"<<endl;
			return ;
	}
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(dp[p[i]]==-1){
			// cout<<i<<" "<<p[i]<<endl;
			cout<<"NO"<<endl;
			return ;
		}
		for(int j=ma;j>=1;j--)
			if(j>=p[i]&&dp[j-p[i]]!=-1)
				dp[j]=1;
	}
	cout<<"YES"<<endl;
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