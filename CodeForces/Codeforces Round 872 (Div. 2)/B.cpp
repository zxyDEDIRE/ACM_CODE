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
ll p[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>p[i];
	sort(p+1,p+1+n*m);
	ll ans=1ll*(p[n*m]-p[1])*(n*m-min(n,m));
	ans+=1ll*(p[n*m]-p[2])*min(n-1,m-1);
	// cout<<ans<<endl;

	ll ans_1=(p[n*m]-p[1])*(n*m-min(n,m));
	ans_1+=(p[n*m-1]-p[1])*min(n-1,m-1);
	cout<<max(ans,ans_1)<<endl;
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
10 -3 8
7 8 9

13 13
13 13
13*4 =52+2
2


-3 10
0
*/