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
	system("g++ gen.cpp -o gen.exe");
	system("g++ std.cpp -o std.exe");
	char tmp[100];
	// sprintf(tmp,"./gen %d > ./data/%d.in",i,i);
	sprintf(tmp,"./gen.exe 1000000 10 1111> ./data/test.in");
	system(tmp);
	// sprintf(tmp,"./std.exe < ./data/test.in > ./data/test.out");
	// system(tmp);

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}