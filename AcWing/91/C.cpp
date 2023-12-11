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
	int n,m,ma=0;
	cin>>n>>m;
	vector<vector<int>>mp(n+1,vector<int>(m+1,0));
	vector<vector<int>>v(n+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j],ma=max(ma,mp[i][j]);
	
	auto check=[&](int mid)->bool{
		map<int,int>vis;
		for(int j=1;j<=m;j++)
		{
			int flag=0;
			for(int i=1;i<=n;i++)
				if(mp[i][j]>=mid)vis[i]++,flag=1;
			if(!flag)return 0;
		}
		for(int i=1;i<=n;i++)
			if(vis[i]>1)return 1;
		return 0;
	};

	int l=1,r=ma,ans=1;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid;
		else r=mid;
	}
	while(check(ans+1))ans++;
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
2
1 3
3 4
*/