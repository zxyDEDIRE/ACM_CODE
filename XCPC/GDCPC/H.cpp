#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int mod=998244353;
map<string,int>mp;
void init()
{
	mp["Zi"]=1;
	mp["Chou"]=2;
	mp["Yin"]=3;
	mp["Mao"]=4;
	mp["Chen"]=5;
	mp["Si"]=6;
	mp["Wu"]=7;
	mp["Wei"]=8;
	mp["Shen"]=9;
	mp["You"]=10;
	mp["Xu"]=11;
	mp["Hai"]=12;
}

char a[6][3];
void change(int r,int k)
{
	if(k==1)
		return;
	if(k==2)
	{
		a[r+0][1]=' ';
		return;
	}
	if(k==3)
	{
		a[r+1][1]=' ';
		return;
	}
	if(k==4)
	{
		a[r+0][1]=' ';
		a[r+1][1]=' ';
		return;
	}
	if(k==5)
	{
		a[r+2][1]=' ';
		return;
	}
	if(k==6)
	{
		a[r+0][1]=' ';
		a[r+2][1]=' ';
		return;
	}
	if(k==7)	
	{
		a[r+1][1]=' ';
		a[r+2][1]=' ';
		return;
	}
	if(k==8)
	{
		a[r+0][1]=' ';
		a[r+1][1]=' ';
		a[r+2][1]=' ';
		return;
	}
}
void cd(int r)
{
	if(a[r][1]=='-')
		a[r][1]=' ';
	else
		a[r][1]='-';
}
int main()
{
	init();
	string yy,hh;
	int y,m,d,h;
	cin>>yy>>m>>d>>hh;
	y=mp[yy];
	h=mp[hh];
	
	int shang,xia,dong;
	shang=(y+m+d)%8;
	if(shang==0)shang=8;
	xia=(y+m+d+h)%8;
	if(xia==0)xia=8;
	dong=(y+m+d+h)%6;
	if(dong==0)dong=6;
	
	
	for(int i=0;i<6;i++)
		for(int j=0;j<3;j++)
			a[i][j]='-';
			
	change(0,shang);
	change(3,xia);
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<3;j++)
			cout<<a[i][j];
		cout<<"\n";
	}
	
	cout<<"\n";
	
	cd(6-dong);
	
	
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<3;j++)
			cout<<a[i][j];
		if(i<5)cout<<"\n";
	}
	
}
