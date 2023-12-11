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
const int N=1e4+111;
bitset<N>dp[N];
int a[N];
int b[N];
int n,k,sum_a=0,sum_b=0;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],sum_a+=a[i];
	for(int j=1;j<=n;j++)
		cin>>b[j],sum_b+=b[j];
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int x=sum_a;x>=0;x--)
		{
			if(x-a[i]>=0)
				dp[x]=dp[x]|(dp[x-a[i]]<<(b[i]));
		}
	}
	for(int i=sum_a;i>=1;i--)
		if(i%k==0&&dp[i][i/k]){
			cout<<i<<endl;
			return ;
		}
	cout<<-1<<endl;
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
21 8
50 39 28 27 58 46 95 46 50 8 28 94 61 58 57 7 1 38 9 34 12
94 1 77 1 17 40 99 31 26 1 1 1 15 7 6 1 85 3 32 65 78

420
352
*/