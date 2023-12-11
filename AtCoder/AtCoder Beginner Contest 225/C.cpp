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
	int n,m;
	cin>>n>>m;
	vector<vector<int>>mp(n+1,vector<int>(m+1,0));

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
			if(mp[i][j+1]-mp[i][j]!=1){
				cout<<"No"<<endl;
				return ;
			}
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<n;i++)
			if(mp[i+1][j]-mp[i][j]!=7){
				cout<<"No"<<endl;
				return ;
			}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mp[i][j]%7==0&&j!=m){
				cout<<"No"<<endl;
				return ;
			}
	cout<<"Yes"<<endl;
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