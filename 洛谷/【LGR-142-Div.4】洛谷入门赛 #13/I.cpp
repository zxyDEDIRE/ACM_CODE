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
	int a, b, c;
	srand(time(0));

	while(1)
	{
		a=rand();while(a<1||a>100)a=rand();
		b=rand();while(b<1||b>100)b=rand();
		c=rand();while(c<1||c>100)c=rand();
		int ans=ceil(a/(b-c));

	  	int d = b - c;
	  	if(((a + d - 1) / d)!=ans){
	  		cout<<a<<" "<<b<<" "<<c<<endl;
	  		return ;
	  	}
	}
	cout<<INT_MAX<<" "<<INT_MAX<<" "<<INT_MAX<<endl;
  	

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 freopen("C:\\Users\\tob\\Desktop\\1.in","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
 fclose(stdout);
	return 0;
}
/*


24910 19807 20741

*/