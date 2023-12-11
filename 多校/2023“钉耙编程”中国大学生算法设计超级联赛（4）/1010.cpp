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
	int n,m;
	cin>>n>>m;
	if(n>m)swap(n,m);

	if(n==1)cout<<(m+1)/2<<endl;
	else if(n%3==0||m%3==0)cout<<2<<endl;
	else cout<<1<<endl;

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
2*1 1
2*2 1
2*3 2
2*4 1
2*5 1
2*6 2
2*7 

4*4 1
4*5 1
4*6 2
4*7 1


5*5 1
5*6 2
5*7 1
5*8 1
5*9 2
5*10 1
5*11 1

7*7 1
7*8 1
7*9 2
7*10 2
7*11 1
7*12 2

 
8*8 1
8*9 2
8*10 1
8*11 1
*/
