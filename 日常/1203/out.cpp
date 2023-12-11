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
/*
20 个数据点
5
n<=100

10000  5
100000 10
*/
void solve()
{
	// _sleep(153);
	// srand(time(0));

	// int n=rand()%100000+1;
	// while(n<=80000||n>100000)n=rand()*7%100000+1;
	// int m=rand()%200000+1;
	// while(m<=1000||m>900000)m=rand()*7%100000+1;
	// cout<<n<<" "<<m<<endl;
	// for(int i=1;i<=m;i++)
	// {
	// 	// if(i<=m/3)
	// 	// {
	// 	// 	cout<<1<<" "<<n<<endl;
	// 	// }
	// 	// else
	// 	{
			// int l=rand()%n+1;
			// int r=rand()%n+1;
			// while(l>r||l<=0||r<=0||l>n||r>n){
			// 	l=rand()%(n+1);
			// 	r=rand()%(n+1);
			// }
			// cout<<l<<" "<<r<<endl;
	// 	}
		
	// }
	int n=100000;
	vector<pii>v;
	cout<<n<<" "<<n<<endl;
	for(int i=1;i<=n;i++)
	{
		int l=rand()%n+1;
		int r=rand()%n+1;
		while(l>r||l<=0||r<=0||l>n||r>n){
			l=rand()*7%(n+1)+31;
			r=rand()*7%(n+1)+31;
		}
		cout<<l<<" "<<r<<endl;
	}
}
signed main(){
 freopen("C:\\Users\\tob\\Desktop\\0.out","r",stdin);
 freopen("C:\\Users\\tob\\Desktop\\0.in","w",stdout);
		solve();
 fclose(stdin);
 fclose(stdout);
	return 0;
}