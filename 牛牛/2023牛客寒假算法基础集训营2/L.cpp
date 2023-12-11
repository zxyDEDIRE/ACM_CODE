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
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int mod=998244353;
int cnt[maxn];
int ans[maxn];
int t[maxn];
int p[maxn];
int n;
void solve()
{
	cin>>n>>mod;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cnt[(p[i]*p[j])%mod]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		// cout<<i<<endl;
		for(int j=1;j<=n;j++)
			if(i!=j)
				cnt[(p[i]*p[j])%mod]--;
		for(int j=0;j<mod;j++){
			// cout<<j<<" "<<p[i]<<" "<<(j-p[i]+mod)%mod<<endl;
			t[j]+=cnt[(j-p[i]%mod+mod)%mod]*2;
		}
		for(int j=1;j<=n;j++)
			if(i!=j)
				cnt[(p[i]*p[j])%mod]++;
			// break;
		// cout<<endl;
	}
	for(int i=0;i<mod;i++)
		cout<<t[i]<<" ";
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
%2
1 2 3
1*2+3
2*1+3
1*3+2

*/