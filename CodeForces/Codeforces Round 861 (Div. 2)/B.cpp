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
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>>mp(m+1,vector<int>(n));
	for(int i=0;i<n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[j][i];
	int ans=0;
	for(int j=1;j<=m;j++)
	{
		auto &v=mp[j];
		sort(v.begin(),v.end());
		for(int i=1;i<n;i++)
		{
			ans+=(v[i]-v[i-1])*(n-i)*i;
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
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
3
0 1 2
1 3 5 7
2
6
4
         7
      5
   3
1 

*/