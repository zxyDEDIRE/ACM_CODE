/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
vector<int>v[maxn];
int p[maxn];
ll n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int x=p[i];
		for(int j=2;j*j<=x;j++)
			if(x%j==0)
			{
				v[j].push_back(i);
				while(x%j==0)x/=j;
			}
		if(x!=1)v[x].push_back(i);
	}
	for(int i=2;i<=1e6;i++)
	{
		ll now=1ll*n*(n+1)/2;
		int pre=0;
		for(int j=0;j<(int)v[i].size();j++)
		{
			long long len=v[i][j]-pre-1;
			now-=len*(len+1)/2;
			pre=v[i][j];

		}

		long long len=n-pre;
		now-=len*(len+1)/2;
		ans+=now;
	}
	cout<<ans;
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
10
99 62 10 47 53 9 83 33 15 24

*/