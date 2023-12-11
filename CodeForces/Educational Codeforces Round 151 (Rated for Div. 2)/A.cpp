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
int n,k,x;
int flag=0;
void dfs(int step,int sum)
{
	if(flag)return ;
	if(sum==0)
	{
		cout<<"YES"<<endl;
		cout<<step-1<<endl;
		for(int i=1;i<step;i++)
			cout<<p[i]<<" ";
		cout<<endl;
		flag=1;
		return ;
	}
	for(int i=1;i<=min(sum,k);i++)
	{
		if(i==x)continue;
		p[step]=i;
		dfs(step+1,sum-i);
	}
}
void solve()
{
	cin>>n>>k>>x;
	flag=0;
	dfs(1,n);
	if(!flag)cout<<"NO"<<endl;
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