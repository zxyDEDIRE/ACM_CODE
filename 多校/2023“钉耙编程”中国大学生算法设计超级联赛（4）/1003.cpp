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
int dp[maxn][2];
int a[maxn][2];
int cnt[maxn];
int b[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;cin>>m;
		v[i].resize(m);
		for(auto &j:v[i])cin>>j;
		sort(v[i].begin(),v[i].end());
		cnt[i]=m;
		b[i]=i;

	}
	sort(b+1,b+1+n,[&](int a,int b){
		return cnt[a]<cnt[b];
	});
	for(auto x:v[b[1]])
	{

		for(int i=2;i<=n;i++)
		{
			int fl=lower_bound(v[b[i]].begin(),v[b[i]].end(),x)-v[b[i]].begin();
			
		}
	}




}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
-7
10 8
1 6 10
-5 -9 2 8 5 4 3 3 8
500000000
*/