#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=111;
char ch;
int n;
void solve()
{
	cin>>n>>ch;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<n-i+1;j++)
			cout<<" ";
		cout<<ch;
		if(i>1)
		{
			for(int j=n-i+2;j<n+i-1;j++)
				cout<<" ";
			cout<<ch;
		}
		cout<<endl;
	}
	for(int i=2;i<=n;i++)
	{
		int x=i;
		int y=n*2-i;
		for(int j=1;j<x;j++)
			cout<<" ";
		cout<<ch;
		if(i!=n)
		{
			for(int j=x+1;j<y;j++)
				cout<<" ";
			cout<<ch;
		}
		cout<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
     o
    o o
   o   o
  o     o
 o       o
o         o
 o       o
  o     o
   o   o
    o o
     o
*/