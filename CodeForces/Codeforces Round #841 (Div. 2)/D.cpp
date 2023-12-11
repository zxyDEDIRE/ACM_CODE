/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int n,m;
void solve()
{
	cin>>n>>m;
	vector<vector<int>>mp(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];

	auto check=[=](int k)->bool{
		vector<vector<int>>p(n+1,vector<int>(m+1,0));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				p[i][j]=((mp[i][j]>=k)+p[i-1][j]+p[i][j-1]-p[i-1][j-1]);
		for(int i=k;i<=n;i++)
			for(int j=k;j<=m;j++)
				if(p[i][j]+p[i-k][j-k]-p[i][j-k]-p[i-k][j]>=k*k)
					return 1;
		return 0;
	};

	int l=1,r=n,ans=1;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		int fl=check(mid);
		if(fl)ans=mid,l=mid;
		else r=mid;
	}
	// cout<<check(3)<<endl;
	if(check(ans+1))cout<<ans+1<<endl;
	else cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\a.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\b.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
 // fclose(stdin);
 // fclose(stdout);
	return 0;
}
/*
5 6
1 9 4 6 5 8
10 9 5 8 11 6
24 42 32 8 11 1
23 1 9 69 13 3
13 22 60 12 14 17


*/