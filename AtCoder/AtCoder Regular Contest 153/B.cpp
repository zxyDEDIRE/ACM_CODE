/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
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
	int n,m,X=0,Y=0;
	cin>>n>>m;
	vector<vector<char>>mp(n,vector<char>(m));
	vector<vector<char>>ans(n,vector<char>(m));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>mp[i][j];
	int q;cin>>q;
	X=0,Y=0;
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		X=(x-1-X+n)%n;
		Y=(y-1-Y+m)%m;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x=i,y=j;
			if(q&1)
			{
				x=(X+n-x)%n;
				y=(Y+m-y)%m;
				ans[x][y]=mp[i][j];
			}
			else
			{
				x=(X+x+n)%n;
				y=(Y+y+m)%m;
				ans[x][y]=mp[i][j];
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<ans[i][j];
		cout<<endl;
	}
}
/*
1 2 3 4 5
0 1 2 3 4 
3 2 1 5 4 /3
5 1 2 3 4 /4
1 5 4 3 2 /2

3 2 1 5 4 /3
2 3 4 5 1 /2
2 1 5 4 3 /1
*/
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