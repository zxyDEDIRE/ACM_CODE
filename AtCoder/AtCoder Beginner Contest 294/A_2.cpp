/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
void solve()
{
	int n=1e7;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		x=sqrtl(x);
		ans=(ans+x)%mod;
	}
	cout<<ans<<endl;
}
signed main(){
 	freopen("C:\\Users\\tob\\Desktop\\in.txt","r",stdin);
 	freopen("C:\\Users\\tob\\Desktop\\out.txt","w",stdout);

	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);

	clock_t start, finish;
	start = clock();

		solve();

	finish = clock();
	cout << "the time cost is" <<\
	double(finish - start) / CLOCKS_PER_SEC;

 	fclose(stdin);
 	fclose(stdout);
	return 0;
}
/*
10000008
the time cost is0.161
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
void solve()
{

}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)
		solve();
}