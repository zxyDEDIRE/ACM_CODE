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
int n;
bool ok(int x)
{
	ll ans_1=1;
	ll sum_1=0;
	for(int i=1;i<x;i++)
		ans_1*=p[i];
	for(int i=1;i<x;i++)
		sum_1+=ans_1/p[i];
	return ans_1==sum_1;
}
void dfs(int x,int y)
{
	if(x==n+1&&ok(x))
	{
		for(int i=1;i<x;i++)
			cout<<p[i]<<" ";
		cout<<endl;
		return ;
	}
	if(x==n+1)return ;
	for(int i=y;i<=100;i++)
	{
		p[x]=i;
		dfs(x+1,i+1);
	}
	return ;
}
void solve()
{
	cin>>n;
	dfs(1,1);
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
2 3 6
2 3 7 42
2 3 9 30 45
2 3 12 30 36 45
2 3 16 30 36 45 48
2 4 10 21 35 36 42 45
*/