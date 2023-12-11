#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cout.tie(0);
#define int long long
typedef long long ll;
typedef pair<int,int> P;
int n,m;
char s[503][503];
int vis[503][503][2];//A1 B2 no3
int OK(int x,int y)
{
	return x<=n&&y<=m&&x>=1&&y>=1;
}
int dfs1(int x,int y,int fl)//fl Alice1 Bob0
{
	int &res=vis[x][y][fl];
	if(res!=-1)return res;
	if(s[x][y]=='A')return res=1;
	else if(s[x][y]=='B')return res=0;
	if(x==n&&y==m)return res=0;
	if(fl){
		int t=0;
		if(OK(x+1,y))t|=dfs1(x+1,y,fl^1);
		if(OK(x,y+1))t|=dfs1(x,y+1,fl^1);
		if(t)return res=1;
		return res=0;
	}
	else {
		int t=1;
		if(OK(x+1,y))t&=dfs1(x+1,y,fl^1);
		if(OK(x,y+1))t&=dfs1(x,y+1,fl^1);
		if(t)return res=1;
		return res=0;
	}
}

int dfs2(int x,int y,int fl)//fl Alice1 Bob0 need draw
{
	int &res=vis[x][y][fl];
	if(res!=-1)return res;
	if(s[x][y]=='A'||s[x][y]=='B')return res=0;
	if(n==x&&y==m)return res=1;
	if(fl){
		int t1=0,t2=0;
		if(OK(x,y+1)&&s[x][y+1]=='.')t1=1;
		if(t1)t1&=dfs2(x,y+1,fl^1);
		if(OK(x+1,y)&&s[x+1][y]=='.')t2=1;
		if(t2)t2&=dfs2(x+1,y,fl^1);
		if(t1||t2)return res=1;
		else return res=0;
	}
	else{
		int t1=0,t2=0;
		if(OK(x,y+1)&&s[x][y+1]=='B')return res=0;
		if(OK(x+1,y)&&s[x+1][y]=='B')return res=0;
		if(OK(x,y+1)&&s[x][y+1]=='A'&&OK(x+1,y)&&s[x][y+1]=='A')return 0;
		if(OK(x,y+1)&&s[x][y+1]=='.')t1=dfs2(x,y+1,fl^1);
		if(OK(x+1,y)&&s[x][y+1]=='.')t2=dfs2(x+1,y,fl^1);
		if(t1||t2)return res=1;
		else return res=0;
	}
}

int dfs3(int x,int y)
{
	int &res=vis[x][y][0];
	if(res!=-1)return res;
	if(s[x][y]=='B')return res=1;
	else if(s[x][y]=='A')return res=0;
	if(x==n&&m==m)return res=0;
	int t=0;
	if(OK(x,y+1))t|=dfs3(x,y+1);
	if(OK(x+1,y))t|=dfs3(x+1,y);
	return res=t;
}
void solve()
{
	cin>>n>>m;
	int fl=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>s[i][j];
			if(s[i][j]=='B')fl=1;
		}
	}
	memset(vis,-1,sizeof(vis));
	if(dfs1(1,1,1))cout<<"yes"<<" ";
	else cout<<"no"<<" ";
	memset(vis,0,sizeof(vis));
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			if(i==n&&j==m&&s[i][j]=='.'){
				vis[i][j][0]=1;
				continue;
			}
			if(s[i][j]=='A'||s[i][j]=='B'){
				vis[i][j][0]=0;
				continue;
			}
			if((i+j)%2){//B
				if(j==m){
					if(vis[i+1][j][0]==0)continue;
					vis[i][j][0]=1;
				}
				else if(i==n){
					if(vis[i][j+1][0])continue;
					vis[i][j][0]=1;
				}
				else {
					if(s[i+1][j]=='B'||s[i][j+1]=='B')continue;
					if(vis[i][j+1][0]||vis[i+1][j][0])vis[i][j][0]=1;
				}
			}
			else{//A
				if(j==m){
					if(vis[i+1][j][0]==0)continue;
					vis[i][j][0]=1;
				}
				else if(i==n){
					if(vis[i][j+1][0])continue;
					vis[i][j][0]=1;
				}
				else {
					if(vis[i][j+1][0]||vis[i+1][j][0])vis[i][j][0]=1;
				}
			}
		}
	}
	if(vis[1][1][0])cout<<"yes ";
	else cout<<"no ";

	memset(vis,-1,sizeof(vis));
	if(dfs3(1,1))cout<<"yes"<<endl;
	else cout<<"no"<<endl;
}
signed main()
{
	//IOS
	int __=1;
	cin >> __;
	while (__--)
		solve();
}
/*
3 3
..A
...
B..

110
011
111
n y y


*/