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
const int N=2222;
char mp[N][N];
char a[N][N];
int n;
int A()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=mp[i][j];
	int ans=0;
	for(int j=1;j<=n;j++)
	{
		if(a[1][j]=='0')continue;
		ans++;
		for(int i=1;i<=n;i++)
			a[i][j]^=1;
	}
	int ans_1=ans;
	int ans_2=ans;
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=n;j++)
			if(a[i][j]!=a[i][j-1])return INF;
		if(a[i][1]=='1')ans_1++;
		else ans_2++;
	}
	return min(ans_1,ans_2);
}
int B()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=mp[i][j];
	int ans=0;
	for(int j=1;j<=n;j++)
	{
		if(a[1][j]=='1')continue;
		ans++;
		for(int i=1;i<=n;i++)
			a[i][j]^=1;
	}
	int ans_1=ans;
	int ans_2=ans;
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=n;j++)
			if(a[i][j]!=a[i][j-1])return  INF;
		if(a[i][1]=='1')ans_1++;
		else ans_2++;
	}
	return min(ans_1,ans_2);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>mp[i]+1;
	int ans_1=A();
	int ans_2=B();
	int mi=min(ans_1,ans_2);
	if(mi==INF)cout<<-1<<endl;
	else cout<<mi<<endl;
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
5
01111
01111
01111
10000
01111

3
111
000
000
*/