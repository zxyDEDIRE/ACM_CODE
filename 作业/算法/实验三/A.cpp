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
const int N=1e3+1000;
int dp[N];
int v[maxn];
int w[maxn];
int n,m;
void solve()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i]>>v[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=0;j--)
		{
			if(j>=w[i])
				dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	cout<<dp[m]<<endl;
}
signed main(){
 freopen("C:\\Users\\tob\\Desktop\\in_1.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		clock_t start, finish;
	start = clock();
	/*******代码*******/
	solve();
	/****************/
	finish = clock();
	 cout << "the time cost is" <<\
	  double(finish - start) / CLOCKS_PER_SEC;
 fclose(stdin);
//  fclose(stdout);
	return 0;
}