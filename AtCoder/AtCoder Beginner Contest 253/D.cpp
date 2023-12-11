/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
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
const int INF=1e9+7;
const int maxn=1e6+100;
int n,a,b,ans;
void solve()
{
	cin>>n>>a>>b;
	ans=(1+n)*n/2;

	int a_ma=floor(n/a)*a;
	int a_mi=a;
	int b_ma=floor(n/b)*b;
	int b_mi=b;
	ans-=(a_ma+a_mi)*(a_ma/a_mi)/2;
	ans-=(b_ma+b_mi)*(b_ma/b_mi)/2;

	int c_mi=a*b/__gcd(a,b);
	int c_ma=floor(n/c_mi)*c_mi;
	ans+=(c_mi+c_ma)*(c_ma/c_mi)/2;
	cout<<ans<<endl;

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
/*
*/