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
int d[35];
int n;
void insert(int x)
{
	for(int i=29;i>=0;i--)
	{
		if((x>>i)&1)
		{
			if(!d[i]) {
				d[i]=x;return;
			}
			x^=d[i];
		}
	}
}
void gauss()
{
	for(int i=0;i<=29;i++)
	{
		if(d[i])
		{
			for(int j=i+1;j<=29;j++)
			{
				if((d[j]>>i)&1)
				d[j]^=d[i];
			}
		}
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		insert(z);
	}
	gauss();
	int ans=0;
	for(int i=0;i<=29;i++) ans+=d[i];
	cout<<ans;
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