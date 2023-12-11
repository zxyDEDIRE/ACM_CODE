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
const int N=333;
char mp[N][N];
int n,k;
void NO(){cout<<"error\n";}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>mp[i][j];
	int x=100;
	int y=k;
	int g=__gcd(x,y);
	x=x/g;
	y=y/g;
	y=y-x+1;
	if(n%x!=0)return NO();
	for(int i=1;i<=n;i++)
	{
		int len=0;
		for(int j=1;j<=n;j++)
		{
			if(mp[i][j]!=mp[i][j-1])
			{
				if(len%x!=0)return NO();
				len=1;
			}
			else len++;
		}

		len=0;
		for(int j=1;j<=n;j++)
		{
			if(mp[j][i]!=mp[j-1][i])
			{
				if(len%x!=0)return NO();
				len=1;
			}
			else len++;
		}
	}

	for(int i=1;i<=n;i++)
	{
		int T=1;
		if(i%x==0)T=y;
		for(int _i=1;_i<=T;_i++)
		{
			for(int j=1;j<=n;j++)
			{
				int S=1;
				if(j%x==0)S=y;
				for(int _j=1;_j<=S;_j++)
					cout<<mp[i][j];
			}
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