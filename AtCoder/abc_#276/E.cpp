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
struct node{
	int x,y,id;
};
vector<string>mp;
int sx,sy;
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		mp.push_back(str);
		for(int j=0;j<m;j++)
			if(mp[i][j]=='S')
				sx=i,sy=j;
	}
	vector<vector<int>>vis(n, vector<int>(m));
	queue<node>q;
	for(int i=0;i<4;i++)
	{
		int xx=sx+dx[i];
		int yy=sy+dy[i]; 
		if(xx<0||yy<0||xx>=n||yy>=m)continue;
		if(mp[xx][yy]!='.')continue;
		q.push({xx,yy,i+1});
	}
	vis[sx][sy]=10;
	while(!q.empty())
	{
		auto [x,y,id]=q.front();q.pop();
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<0||yy<0||xx>=n||yy>=m)continue;
			if(mp[xx][yy]!='.')continue;
			if(vis[xx][yy]!=0&&vis[xx][yy]!=id){
				// cout<<vis[xx][yy]<<endl;
				// cout<<x<<" "<<y<<" "<<id<<endl;
				// cout<<xx<<" "<<yy<<" "<<id<<endl;
				cout<<"Yes"<<endl;
				return ;
			}
			if(vis[xx][yy]>0)continue;
			vis[xx][yy]=id;
			q.push({xx,yy,id});
		}
	}
	cout<<"No"<<endl;


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
/*
5 7
.#.....
..#.#..
...S...
..#.#..
.#...#.


3 3
...
#S#
...
*/