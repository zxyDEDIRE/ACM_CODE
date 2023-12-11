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
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int p[maxn];
ll a[maxn];
int n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n*2;i++)
		cin>>p[i],a[i%k]+=p[i];
	for(int i=1;i<=n*2;i++)
	{
		if((i%2)==0)
			cout<<p[i]<<" ";
		else cout<<(a[i%k])%i<<" ";
	}
	cout<<endl;
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
10 4
5 2 0 4 7 6 2 7 1 3 5 7 9 45 3 6 12 36 78 1
0 2 1 4 4 6 4 7 7 3 0 7 8 45 13 6 0 36 12 1
0 2 1 4 4 6 4 7 7 3 0 7 8 45 13 6 0 36 12 1
*/