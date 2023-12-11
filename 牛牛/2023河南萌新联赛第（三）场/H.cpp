/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
bool dp[maxn];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	// n=1e5;
	for(int i=1;i<=n;i++)
		cin>>p[i];
		// p[i]=i;
	sort(p+1,p+1+n);
	int sum=0;
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(p[i]>sum+1)break;
		// for(int j=0;j<=sum;j++){
		// 	if(dp[j]==0){
		// 		cout<<j<<endl;
		// 		return ;
		// 	}
		// 	dp[j+p[i]]|=dp[j];
		// }
		sum+=p[i];
	}
	cout<<sum+1<<endl;
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
1 2 5 9
*/