#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
const int N=1e3;
struct node{
	int x,y;
}p[maxn];
string str;
int a[100][100];
int b[100][100];
int n;
void solve()
{
	memset(a,0,sizeof(a));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>str;
		int x=str[0]-'a'+1;
		int y=str[1]-'a'+1;
		p[i].x=x;
		p[i].y=y;
		a[x][y]++;
	}
	long long res=0;
	for(int i=1;i<=n;i++)
	{
		int x=p[i].x;
		int y=p[i].y;
		for(int j=1;j<=26;j++)
		{
			if(j!=y)res+=a[x][j];
			if(j!=x)res+=a[j][y];
		}
	}
	cout<<res/2<<endl;
}
signed main(){
	int __;cin>>__;
	while(__--)solve();
}
/*
BBBRWWRRRWBR
*/