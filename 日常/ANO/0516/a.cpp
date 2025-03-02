#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2000+10;
string mp[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>mp[i];
	int ma=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int x=i,y=0,cnt=0;
		int xx=i,yy=0,cn=0;
		for(int j=0;j<n;j++)
		{
			if(mp[i][j]=='1')ans++;

			if(mp[x][y]=='1')cnt++;
			x++,y++;
			x%=n,y%=n;

			if(mp[xx][yy]=='1')cn++;
			xx++,yy--;
			xx%=n;
			yy=(yy+n)%n;
		}
		ma=max(ma,cnt);
	}
	cout<<ans-ma+(n-ma)<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)solve();
}
/*
3 2 1 0

00010
00001
10000
01000
00100
*/