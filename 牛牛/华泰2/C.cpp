#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+100;
int mp[maxn][maxn];
bool vis[maxn][maxn];
struct node{
	int x,y;
}a,b;
int n,m;
void f(node &b,int x,int y,int _x,int _y)
{
	int peng=0,peng_fl;
	while(b.x!=x)
	{
		int f1;
		char f2;
		if(x>b.x)f1=1,f2='W';
		else f1=-1,f2='S';
		if(b.x+f1==_x&&b.y==_y)
		{
			peng=1;
			peng_fl=f1;
			break;
		}
		else cout<<f2,b.x+=f1;
	}
	// cout<<peng<<endl;
	if(peng&&peng_fl==1)
	{
		if(b.y>1)cout<<"AWWD";
		else if(b.y<m)cout<<"DWWA";
		b.x=x;
	}
	else if(peng&&peng_fl==-1)
	{
		if(b.y>1)cout<<"ASSD";
		else if(b.y<m)cout<<"DSSA";
		b.x=x;
	}
	peng=0;
	while(b.y!=y)
	{
		int f1;
		char f2;
		if(y>b.y)f1=1,f2='D';
		else f1=-1,f2='A';
		if(b.y+f1==_y&&b.x==_x)
		{
			peng=1;
			peng_fl=f1;
			break;
		}
		else cout<<f2,b.y+=f1;
	}
	// cout<<peng<<endl;
	if(peng&&peng_fl==1)
	{
		if(b.x>1)cout<<"WDDS";
		else if(b.x<n)cout<<"SDDW";
		b.y=y;
	}
	else if(peng&&peng_fl==-1)
	{
		if(b.x>1)cout<<"WAAS";
		else if(b.x<n)cout<<"SAAW";
		b.y=y;
	}
}
void ff(node&a,int x,int y,int _x,int _y)
{
	int peng=0;
	while(a.x!=x||a.y!=y)
	{
		int f1=0,f2=0;
		char F1,F2;
		if(x>a.x)f1=1,F1='W';
		else if(x<a.x)f1=-1,F1='S';
		if(y>a.y)f2=1,F2='A';
		else if(y<a.y)f2=-1,F2='D';
		if(a.x!=x&&!(a.x+f1==_x&&a.y==_y))
			cout<<F1,a.x+=f1;
		else if(a.y!=y&&!(a.y+f2==_y&&a.x==_x))
			cout<<F2,a.y+=f2;
		else {
			peng=1;
			break;
		}
	}
	if(peng)
	{
		if(_x==a.x+1)
		{
			if(a.y>1)cout<<"DWWA";
			else cout<<"AWWD";
		}
		else if(_x==a.x-1)
		{
			if(a.y>1)cout<<"DSSA";
			else cout<<"ASSD";
		}
		else if(_y==a.y+1)
		{
			if(a.x<1)cout<<"SAAW";
			else cout<<"WAAS";
		}
		else if(_y==a.y-1)
		{
			if(a.x<1)cout<<"SDDW";
			else cout<<"WDDS";
		}
	}
	a.x=x;
	a.y=y;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			if(mp[i][j]==1)
				a={i,j};
			if(mp[i][j]==0)
				b={i,j};
		}
	while(a.x!=1)
	{
		ff(b,a.x-1,a.y,a.x,a.y);
		// cout<<b.x<<" "<<b.y<<" "<<a.x-1<<" "<<a.y<<endl;
		cout<<"W";
		swap(a,b);
	}
	// cout<<"  SDFSD"<<endl;
	// cout<<a.x<<" "<<a.y<<endl/;
	while(a.y!=1)
	{
		ff(b,a.x,a.y-1,a.x,a.y);
		cout<<"A";
		swap(a,b);
	}
	cout<<endl;

}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
1
3 3
2 2 2
1 3 2
0 2 2
*/