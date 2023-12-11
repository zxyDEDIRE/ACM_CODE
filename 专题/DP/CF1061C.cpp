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
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int dp[maxn];
int p[maxn];
int n,ans;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		vector<int>v;
		for(int j=2;j<=sqrt(x);j++)
			if(x%j==0){
				v.push_back(j);
				if(x/j!=j)v.push_back(x/j);
			}
		if(x>1)
			v.push_back(x);
		sort(v.begin(),v.end(),[&](int a,int b){
			return a>b;
		});
		for(auto j:v)
		{
			dp[j]+=dp[j-1];
			ans+=dp[j-1];
			dp[j]%=mod;
			ans%=mod;
		}
		ans++;
		dp[1]++;
	}
	cout<<ans%mod<<endl;
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