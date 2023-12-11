/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e18+7;
const int maxn=1e6+100;
void solve()
{
	int n;
	cin>>n;
	int ans=sqrtl(n-1);
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
	// 		clock_t start, finish;
	// start = clock();
	/*******代码*******/
	solve();
	/****************/
	// finish = clock();
	// cout << "the time cost is" <<\
	// double(finish - start) / CLOCKS_PER_SEC;
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1e7 20 sqrt 20 0.252   1-i
1e7 20 sqrt 17 0.208   1-i
1e7 20 sqrt 17 0.195 q 1-i
1e7 20 sqrt 17 0.436 q 1-i
*/