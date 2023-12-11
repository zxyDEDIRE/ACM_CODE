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
void solve()
 {   
	 int n, P;
	 cin >> n >> P;
	 map<int, int> mp;
	 p[0] = 0;
	 for(int i = 1; i <= n; i++ ) {
		 cin >> p[i];
		 mp[p[i]] = 1;
	 }
	 bool flag = true;
	 for(int i = 0; i < p[n]; i++ )
		 if(!mp[i]) {
			 flag = false;
			 break;
		 }
	 if(flag) {
		 int cur = P - 1;
		 while(mp[cur]) cur -- ;
		 cout << max(0ll, cur - p[n]) << endl;
	 } else {
		 int ans = P - p[n]; 
		 for (int i = n - 1; ~i ; i -- ) {
			 p[i] ++ ;
			 if(p[i] == P) p[i] = 0;
			 mp[p[i]] = 1;
			 if(p[i]) break;
		 }
		 int cur = p[n] - 1;
		 while(mp[cur]) cur -- ;
		 ans += max(0ll, cur);
		 cout << ans << endl;
	 }
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