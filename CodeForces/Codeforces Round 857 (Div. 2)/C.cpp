/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=100000000000000013;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int mp[222][222];
void init()
{
	srand(time(0));
	mp[1][1]=0;
	mp[1][2]=1;
	mp[2][1]=2;
	mp[2][2]=3;
	int ma=0;
	for(int i=3;i<=200;i++)
	{
		mp[1][i]=mp[1][i-2]+4;
		mp[2][i]=mp[2][i-2]+4;
	}
	for(int i=3;i<=200;i++)
		for(int j=1;j<=200;j++)
			mp[i][j]=mp[i-2][j]+1024;
}
void solve()
{
	int n,m;
	cin>>n>>m;
	cout<<n*m<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cout<<mp[i][j]<<" ";
		cout<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	init();
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}