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
void solve()
{
	int T=1;
	cout<<T<<endl;
	srand(time(0));
	while(T--)
	{
		int n=1000 ; 
		int m=5;
		int T=1e5;
		cout<<n<<" "<<m<<endl;
		for(int i=1;i<=n;i++)
		{
			int x=rand()%T+1;
			cout<<x<<" ";
		}
		cout<<endl;
		for(int i=1;i<=n;i++)
		{
			int x=rand()%T+1;
			cout<<x<<" ";
		}
		cout<<endl;
		for(int i=1;i<=n;i++)
		{
			int x=rand()%n+1;
			cout<<x<<" ";
		}
		cout<<endl;
		for(int i=1;i<=m;i++)
		{
			int x=rand()%n+1;
			cout<<x<<" ";
			int y=rand()%n+10;
			cout<<y<<" ";
			int z=rand()%T+1;
			cout<<z<<endl;
		}
	}
	
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 freopen("in.txt","w",stdout);
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
1
30 5
23520 17873 36941 93482 5499 43823 1380 51705 95846 19361 24497 87055 51996 16435 10047 45459 81710 37848 43474 8224 81915 68222 57803 13308 26048 30053 12002 24943 92959 48180
66319 32830 82404 19612 42664 4254 63434 44043 55959 75631 63403 96807 62685 15398 29593 89083 77208 27655 26931 20682 52230 8845 5255 10033 38504 31302 56437 66857 72597 49396
19 25 27 24 16 30 28 1 22 6 21 7 14 28 6 17 30 24 11 12 27 10 8 23 24 13 26 21 20 22
8 17 91797
4 32 66674
4 29 4985
17 26 18925
15 10 11902
*/