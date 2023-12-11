/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
const int N=300;
int a[N][N];
int b[N][N];
int c[N][N];
int n,m,k;
void solve()
{
	cin>>n>>m>>k;
	for(int z=1;z<=k;z++)
		for(int x=1;x<=n;x++)
			for(int y=1;y<=m;y++)
			{
				int op;cin>>op;
				if(op==1)
				{
					a[x][z]=1;
					b[y][z]=1;
					c[x][y]=1;
				}
			}
	for(int z=k;z>=1;z--){
		for(int x=1;x<=n;x++)
			cout<<a[x][z]<<" ";
		cout<<endl;
	}
	// cout<<endl;

	for(int z=k;z>=1;z--){
		for(int y=m;y>=1;y--)
			cout<<b[y][z]<<" ";
		cout<<endl;
	}
	// cout<<endl;
	for(int y=m;y>=1;y--){
		for(int x=1;x<=n;x++)
			cout<<c[x][y]<<" ";
		cout<<endl;
	}


}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}