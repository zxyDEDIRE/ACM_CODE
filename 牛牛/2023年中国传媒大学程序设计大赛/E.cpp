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
map<vector<vector<int>>,int>mp;
int s[4][4],flag,ans=INF;
void doit(vector<vector<int>> &p,int x,int y)
{
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx>=0&&yy>=0&&xx<3&&yy<3)
		{
			p[xx][yy]^=1;
		}
	}
	p[x][y]^=1;
}
void bfs(vector<vector<int>>s)
{
	queue<vector<vector<int>>>q;
	q.push(s);
	while(!q.empty())
	{
		auto x=q.front();q.pop();
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				vector<vector<int>> y=x;
				doit(y,i,j);
				if(!mp.count(y)||mp[y]>mp[x]+1){
					mp[y]=mp[x]+1;
					q.push(y);
				}
			}
		}
	}
}
void solve()
{
	vector<vector<int>>p(3,vector<int>(3,0));
	vector<vector<int>>t(3,vector<int>(3,0));
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			cin>>p[i][j];
	// dfs(p,0);
	bfs(p);
	cout<<mp[t]<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}