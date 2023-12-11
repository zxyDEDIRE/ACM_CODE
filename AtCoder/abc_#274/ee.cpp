/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
double dis[1<<18][20];
int X[100],Y[100];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>X[i]>>Y[i];
	for(int i=n+1;i<=n+m;i++)
		cin>>X[i]>>Y[i];
	for(int i=0;i<1<<n+m;i++)
		for(int j=1;j<=n+m;j++)
			dis[i][j]=1e150;
	for(int i=1;i<=n+m;i++)
		dis[1<<i][i]=hypot(X[i],Y[i]);
	for(int i=0;i<1<<n+m;i++)
	for(int j=1;j<=n+m;j++)
	if(dis[i][j]<1e100)
	{
		int speed=1<<__builtin_popcount(i>>n);
		
	}

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}