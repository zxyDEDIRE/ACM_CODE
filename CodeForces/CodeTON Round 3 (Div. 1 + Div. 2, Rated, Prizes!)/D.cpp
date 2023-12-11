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
int p[maxn];
int n,m;
 int calc(int n, int top) { 
     vector<pii> divisors;
     for(int i = 2; i * i <= n ; i ++ ) {
         if(n % i == 0) {
             int s = 0;
             while(n % i == 0) n /= i, s ++ ;
             divisors.push_back({i, s});
         }
     }
     if(n > 1) divisors.push_back({n, 1});
  
     int res = 0, m = divisors.size();
     for (int i = 1; i < 1 << m; i ++ )
     {
         int t = 1, s = 0;
         for (int j = 0; j < m; j ++ )
             if (i >> j & 1)
             {
                 if (t * divisors[j].first > top) {
                     t = -1;
                     break;
                 }
                 t *= divisors[j].first;
                 s ++ ;
             }
         if (t != -1) {
             if (s % 2) res += top / t;
             else res -= top / t;
         }
     }
     return top - res;
 }
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=2;i<=n;i++)
		if(p[i-1]%p[i]){
			cout<<0<<endl;
			return ;
		}
	int ans=1;
	for(int i=2;i<=n;i++)
	{
		if(p[i]==p[i-1])
			ans=(ans*(m/p[i]))%mod;
		else
		{
			ans=(ans*calc(p[i-1]/p[i],m/p[i]))%mod;
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
5 2
5 10
*/