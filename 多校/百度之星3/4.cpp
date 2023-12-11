#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cout.tie(0);
#define int long long
typedef long long ll;
typedef pair<int,int> P;
const int N=2e5+7;
const int mod=998244353;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
char s[1003][1003];
int n,m;
int s0,s1,s8;
int check1(int x,int y)
{
	if(s[x][y]=='#'&&s[x+1][y]=='#'&&s[x+2][y]=='#'){
		s[x][y]='.',s[x+1][y]='.',s[x+2][y]='.';
		return 1;
	}
	else if(s[x][y]=='#'&&s[x][y+1]=='#'&&s[x][y+2]=='#'){
		s[x][y]='.',s[x][y+1]='.',s[x][y+2]='.';
		return 1;
	}
	return 0;
}
int check0(int x,int y)
{
	if(s[x][y]=='#'&&s[x+1][y]=='#'&&s[x+2][y]=='#'&&s[x][y+1]=='#'&&s[x+2][y+1]=='#'&&s[x][y+2]=='#'&&s[x+1][y+2]=='#'&&s[x+2][y+2]=='#'&&s[x+1][y+1]=='.'){
		s[x][y]='.',s[x+1][y]='.',s[x+2][y]='.',s[x][y+1]='.',s[x+2][y+1]='.',s[x][y+2]='.',s[x+1][y+2]='.',s[x+2][y+2]='.';
		return 1;
	}
	return 0;
}
int check8(int x,int y)
{
	if(s[x][y]=='#'&&s[x+1][y]=='#'&&s[x+2][y]=='#'&&s[x][y+1]=='#'&&s[x+2][y+1]=='#'&&s[x][y+2]=='#'&&s[x+1][y+2]=='#'&&s[x+2][y+2]=='#'&&s[x][y+3]=='#'&&s[x][y+4]=='#'&&s[x+1][y+4]=='#'&&s[x+2][y+3]=='#'&&s[x+2][y+4]=='#'&&s[x+1][y+1]=='.'&&s[x+1][y+3]=='.'){
		s[x][y]='.',s[x+1][y]='.',s[x+2][y]='.',s[x][y+1]='.',s[x+2][y+1]='.',s[x][y+2]='.',s[x+1][y+2]='.',s[x+2][y+2]='.';
		s[x][y+3]=='.',s[x][y+4]=='.',s[x+1][y+4]=='.',s[x+2][y+3]='.',s[x+2][y+4]='.',s[x+1][y+1]='.',s[x+1][y+3]='.';
		return 1;
	}
	else if(s[x][y]=='#'&&s[x][y+1]=='#'&&s[x][y+2]=='#'&&s[x+1][y]=='#'&&s[x+1][y+1]=='.'&&s[x+1][y+2]=='#'&&s[x+2][y]=='#'&&s[x+2][y+1]=='#'&&s[x+2][y+2]=='#'&&s[x+3][y]=='#'&&s[x+3][y+1]=='.'&&s[x+3][y+2]=='#'&&s[x+4][y]=='#'&&s[x+4][y+1]=='#'&&s[x+4][y+2]=='#'){
		s[x][y]='.',s[x][y+1]='.',s[x][y+2]='.',s[x+1][y]='.',s[x+1][y+1]='.',s[x+1][y+2]='.',s[x+2][y]='.',s[x+2][y+1]='.',s[x+2][y+2]='.',s[x+3][y]='.',s[x+3][y+1]='.',s[x+3][y+2]='.',s[x+4][y]='.',s[x+4][y+1]='.',s[x+4][y+2]='.';
		return 1;
	}
	return 0;
}
void solve()
{
	cin>>n>>m;
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=m+1;j++){
			s[i][j]='.';
		}
	}
	for(int i=1;i<=n;i++){
		getchar();
		for(int j=1;j<=m;j++){
			scanf("%c",&s[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='.')continue;
			if(check8(i,j))s8++;
			//else if(check0(i,j))s0++;
			//else if(check1(i,j))s1++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='.')continue;
			//if(check8(i,j))s8++;
			if(check0(i,j))s0++;
			//lse if(check1(i,j))s1++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='.')continue;
			//if(check8(i,j))s8++;
			//else if(check0(i,j))s0++;
			if(check1(i,j))s1++;
		}
	}

	cout<<s1<<" "<<s0<<" "<<s8<<endl;
}
signed main()
{
	//IOS
	int __=1;
	//cin >> __;
	while (__--)
		solve();
}
/*
#.###.#####
#.#.#.#.#.#
#.###.#####

4 9
.###.....
#########
##.##.#.#
#########
*/