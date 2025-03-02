#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<map>
using namespace std;
int h,w,n;
string s[300];
struct poi
{
	int x,y;
	bool operator<(const poi&a)const{
		if(a.x!=x)return a.x<x;
		return a.y<y;
	}
}a, b;
struct point
{
	int x,y,w;
	bool friend operator<(point c, point b){
		return c.w<b.w;
	}
}p1,p2;
int st[300][300];
map<poi,int>mp;
int dx[4]={0, 0, 1, -1};
int dy[4]={1, -1, 0, 0};
int OK(int x, int y)
{
	return x>=1&&y>=1&&x<=h&&y<=w&&s[x][y]!='#';
}
int main()
{
	cin>>h>>w;
	for(int i=1;i<=h;i++){
		cin>>s[i];
		s[i]=' '+s[i];
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y,e;
		cin>>x>>y>>e;
		a.x=x;
		a.y=y;
		mp[a]=e;
	}
	priority_queue<point>q;
	int sx=0,sy=0;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(s[i][j]=='S'){
				sx=i;
				sy=j;
			}
		}
	}
	p1.x=sx;
	p1.y=sy;
	b.x=sx;
	b.y=sy;
	if(mp[b]==0){
		cout<<"No"<<endl;
		return 0;
	}
	p1.w=0;
	q.push(p1);
	while(q.size()){
		p1=q.top();
		q.pop();
		if(s[p1.x][p1.y]=='T'){
			cout<<"Yes"<<endl;
			return 0;
		}
		if(st[p1.x][p1.y])continue;
		st[p1.x][p1.y]=1;
		for(int i=0;i<4;i++){
			int xx=dx[i]+p1.x;
			int yy=dy[i]+p1.y;
			if(!OK(xx, yy)||p1.w==0)continue;
			p2.x=xx;
			p2.y=yy;
			p2.w=p1.w-1;
			q.push(p2);
			b.x=xx;
			b.y=yy;
			if(mp[b]!=0){
				p2.w=mp[b];
				q.push(p2);
			}
		}
	}
	cout<<"No"<<endl;
}












