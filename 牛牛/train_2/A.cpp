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
int p[maxn];
int n;
bool dfs(int x,int y,int step)
{
	if(y==0)
	{
		for(int i=step-1;i>=1;i--)
			cout<<p[i]<<" ";
		cout<<endl;
		return 1;
	}
	for(int i=x;i>=1;i--)
	{
		if(i*i>y)continue;
		p[step]=i;
		int x=dfs(i-1,y-i*i,step+1);
		if(x==1)return 1;
	}
	return 0;
}
void solve()
{
	cin>>n;
	int x=dfs(n-1,n*n,1);
	if(x==0)cout<<-1;
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