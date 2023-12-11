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
#define int long long
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());   //uint
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());//ull  大概率生成不相同数据
int getRand(int l,int r){
    uniform_int_distribution < int > uid(l,r);
    return uid(rng);
}
signed main(int argc, char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	long long n = atoll(argv[1]);
	cout<<n<<" "<<n+1<<endl;

	return 0;
}