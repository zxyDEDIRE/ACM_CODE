/*！*/
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
const int maxn=1e2+100;
string p[maxn];
int n,m;
bool check(string a,string b)
{
	for(int i=0;i<m;i++)
	{
		if(a[i]=='?')continue;
		if(a[i]!=b[i])return 0;
	}
	return 1;
}
void solve()
{
	cin>>n;
	m=20;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int cnt=0;
	for(int i=0;i<(1<<m);i++)
	{
		string now="";
		for(int j=0;j<m;j++)
			if(i&(1<<j))now=now+"1";
			else now=now+"0";
		int flag=0;
		for(int j=1;j<=n;j++)
			if(check(p[j],now)){
				flag=1;
				break;
			}
		if(flag==0)continue;
		cnt++;
	}
	cout<<cnt<<endl;
}
signed main(){
 // freopen("in.txt","r",stdin);
 // freopen("out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
10000
01000
00001
10001
*/