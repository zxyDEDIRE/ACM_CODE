#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=30;
int p[maxn][maxn];
string a,b,c;
void solve()
{
	cin>>a>>b>>c;
	memset(p,0,sizeof(p));
	for(int i=0;i<12;i++)  
		p[i%4][a[i]-'A']++;
	for(int i=0;i<8;i++)
		p[i%4][b[i]-'A']++;
	for(int i=0;i<4;i++)
		p[i%4][c[i]-'A']++;
	int flag=1;
	for(int i=0;i<4;i++)
	{
		if(p[i]['G'-'A']!=3)flag=0;
		if(p[i]['R'-'A']!=2)flag=0;
		if(p[i]['Y'-'A']!=1)flag=0;
	}
	if(flag)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main(){
	int __;cin>>__;
	while(__--)solve();
}
/*

*/