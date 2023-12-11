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
int mp[1111][1111];
int n,m;
void solve()
{
	cin>>n>>m;
	if(m&1)
	{
		for(int i=1;i<=m;i++)
			mp[1][i]=i;
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(mp[i-1][j]==(i-1)*m)mp[i][j]=mp[i-1][j]+1;
				else mp[i][j]=mp[i-1][j]+m+1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				cout<<mp[i][j]<<" ";
			cout<<endl;
		}
	}
	else
	{
		int now=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				cout<<++now<<" ";
			cout<<endl;
		}
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
1  2  3  4  5  6  7
9  10 11 12 13 14 8
17 18 19 20 21 15 16

*/