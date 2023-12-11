#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=200;
int vis[N][N];
int n,m;
void f(int x,int y)
{
	while(1)
	{
		vis[x][y]=1;
		x++;
		y++;
		if(x>=n||y>=m)return ;
	}
}
void t(int x,int y)
{
	int cnt=0;
	while(1)
	{
		cnt++;
		if(cnt>0&&cnt%5==0)vis[x][y]=1;
		x++;
		y++;
		if(x>=n||y>=m)return ;
	}
}
void solve()
{
	cin>>n>>m;
	if(n<=4&&m<=4)
	{
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				cout<<".";
			cout<<endl;
		}
		return ;
	}
	else if(n<=4&&m<=9)
	{
		int mid=(m)/2;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				if(j==mid)cout<<"o";
				else cout<<".";
			cout<<endl;
		}
		return ;
	}
	else if(n<=9&&m<=4)
	{
		int mid=(n+1);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				if(i==mid)cout<<"o";
				else cout<<".";
			cout<<endl;
		}
		return ;
	}

	for(int i=0;i<n;i++)
		if((i%5)==0)
			f(i,0);
		else t(i,0);


	for(int i=1;i<m;i++)
		if(i%5==0)
			f(0,i);
		else t(0,i);

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			if(vis[i][j])cout<<"o";
			else cout<<".";
		cout<<endl;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
1
3 6
o.....
.o....
..o...

..
..
...o..
..o...
....o.

....o
...o.
..o..
.o...
o....

o....o....
.o....o...
..o....o..
...o....o.
....o.....
.....o....


4 9
....o....
....o....
....o....
....o....
ooooooooo



o....o...
.o....o..
..o....o.
...o....o
....ooooo
13

o....o...
.o....o..
..o....o.
...o....o
ooooooooo
o....o...



o....o...
.o....o..
..o....o.
...o....o
....oo...
o...oo...
.o..o.o..
..o.o..o.
...oo...o
....o....
.....o...



o....o....o....o....o....o....o....o....
.o....o....o....o....o....o....o....o...
..o....o....o....o....o....o....o....o..
...o....o....o....o....o....o....o....o.
....oooooooooooooooooooooooooooooooooooo



o....o....o....o....o....o....o....o...o
.o....o....o....o....o....o....o....o.o.
..o....o....o....o....o....o....o....o..
...o....o....o....o....o....o....o..o...
....oooooooooooooooooooooooooooooooo....


o....o....o....o...o
.o....o....o....o.o.
..o....o....o....o..
...o....o....o..o...
....oooooooooooo....
o...oo....o....o...o
.o..o.o....o....o.o.
..o.o..o....o....o..
...oo...o....o..o...
....o....ooooooo....
o...oo...oo....o....
.o..o.o..o.o....o...
..o.o..o.o..o....o..
...oo...oo...o....o.
....o....o....oooooo
o...oo...oo...oo....
.o..o.o..o.o..o.o...
..o.o..o.o..o.o..o..
...oo...oo...oo...o.
....o....o....o....o

*/