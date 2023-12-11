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
const int N=666;
char mp[N][N];
char a[N][N];
char b[N][N];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			// mp[i][j]=((rand()&1)?'1':'0');
			a[i][j]=b[i][j]=mp[i][j];
		}

	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=m;j++)
	// 		cout<<mp[i][j];
	// 	cout<<endl;
	// }


	for(int i=1;i<=n;i++)
		a[i][1]='1',b[i][m]='1';
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i%2==1&&j!=m)a[i][j]='1';
			if(i%2==0&&j!=1)b[i][j]='1';
		}
	}
	// cout<<endl;
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=m;j++){
	// 		if(a[i][j]==b[i][j]&&a[i][j]=='1')
	// 		{
	// 			if(mp[i][j]=='0'){
	// 				cout<<"NO"<<endl;
	// 				return ;
	// 			}
	// 		}
	// 		else
	// 		{
	// 			if(mp[i][j]=='1'){
	// 				cout<<"NO"<<endl;
	// 				return ;
	// 			}
	// 		}
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cout<<a[i][j];
		cout<<endl;
	}
	// cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cout<<b[i][j];
		cout<<endl;
	}
	// cout<<endl;
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
5 5
00100
00000
01010
01100
00000


5 5
00100
00000
10101
00000
00100

5 9
000000000
001010100
000101110
001010100
000000000


11111
10000
11111
11100
11111

00101
11111
01011
11111
00001


11110
10100
11110
11100
11110
00001
01111
01011
01111
00001

11110
10100
11110
11100
11110
00001
01111
01011
01111
00001

100
001
100

110
101
110

101
011
101
*/