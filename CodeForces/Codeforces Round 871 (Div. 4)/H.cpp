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
const int maxn=2e5+100;
vector<int>v[100];
int cnt[100];
int a[maxn];
ll n,k;
ll doit(int T)
{
	for(int i=1;i<=n;i++)
	{
		if(((a[i]&T)&T)!=T)continue;
		int x=(a[i]^T);
		cnt[x]++;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(((a[i]&T)&T)!=T)continue;
		int x=(a[i]^T);
		for(int j=0;j<66;j++)
			
	}
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ll ans=0;
	for(int j=0;j<64;j++)
	{
		int cnt=0;
		for(int i=0;i<6;i++)
			if(j&(1<<j))cnt++;
		if(cnt!=k)continue;
		ans+=doit(j);
	}
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
5 1
1 1 1 1 1
*/