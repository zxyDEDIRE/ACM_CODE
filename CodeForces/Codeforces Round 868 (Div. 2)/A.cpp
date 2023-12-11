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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int p[maxn];
int n,k;
int f(int x)
{
	if(x==0)return 0;
	if(x==1)return 0;
	return x*(x-1)/2;
}
void solve()
{
	cin>>n>>k;
	if(n==2&&k==0)
	{
		cout<<"YES"<<endl;
		cout<<"-1 1"<<endl;
		return ;
	}
	for(int i=0;i<=n;i++)
	{
		int x=i,y=n-i;
		int sum_x=f(x);
		int sum_y=f(y);
		// cout<<x<<" "<<y<<" "<<sum_x<<" "<<sum_y<<endl;
		if(sum_x+sum_y==k)
		{
			cout<<"YES"<<endl;
			for(int j=1;j<=x;j++)
				cout<<"1 ";
			for(int j=1;j<=y;j++)
				cout<<"-1 ";
			cout<<endl;
			return ;
		}
	}
	cout<<"NO"<<endl;
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
1 1 -1
3 2
5 5



1 1 1
1+3
1 1 1 -1 -1


1 1 1
3*2/2
*/