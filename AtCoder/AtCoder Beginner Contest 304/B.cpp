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
	int n;
	cin>>n;
	if(n<=(1e3-1))cout<<n<<endl;
	else if(n<=(1e4-1))cout<<(n/10*10)<<endl;
	else if(n<=(1e5-1))cout<<(n/100*100)<<endl;
	else if(n<=(1e6-1))cout<<(n/1000*1000)<<endl;
	else if(n<=(1e7-1))cout<<(n/10000*10000)<<endl;
	else if(n<=(1e8-1))cout<<(n/100000*100000)<<endl;
	else cout<<(n/1000000*1000000)<<endl;
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