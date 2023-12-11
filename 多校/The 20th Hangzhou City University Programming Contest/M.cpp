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
ll n,k;
void solve()
{
	cin>>n>>k;
	if(n&1)
	{
		p[1]=k;
		ll now=1;
		for(int i=2;i<=n;i+=2)
		{
			if(now==k)now++;
			p[i]=now;p[i+1]=-now;
			now++;
		}
	}
	else
	{
		p[1]=k;
		ll now=1;
		for(int i=2;i<=n;i+=2)
		{
			if(now==k)now++;
			p[i]=now,p[i+1]=-now;
			now++;
		}
		p[n-1]+=p[n+1];
	}
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" \n"[i==n];
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
10 1 -1 2

*/