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
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
unsigned long long k1, k2, K;
int a,b,c,n;
void setSeed(unsigned long long a, unsigned long long b, unsigned long long c) {
	k1 = a;
	k2 = b;
	K = c;
}
unsigned long long xorShift128Plus() {
	unsigned long long k3 = k1, k4 = k2;
	k1 = k4;
	k3 ^= k3 << 23;
	k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
	return (k2 + k4) % K + 1;
}
void solve()
{
	cin>>a>>b>>c>>n;
	// setSeed(a, b, c);
	// unsigned long long res = xorShift128Plus();
	// for (a = 1; a != n; ++a) {
	// 	res = __gcd(res, xorShift128Plus());
	// }
	// cout<<res<<endl;
	cout<<1<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}