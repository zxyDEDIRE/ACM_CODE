/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define nullptr 0
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=100;
int mp[maxn][maxn];
int x[maxn][maxn];
int y[maxn][maxn];
int z[maxn][maxn];
int n=9;
void solve()
{
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=n;j++)
	// 		cout<<(i-1)/3*3+(j+2)/3<<" ";
	// 	cout<<endl;
	// }
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
			x[i][j]=y[i][j]=z[i][j]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int a;cin>>a;
			x[j][a]++;
			y[i][a]++;
			z[(i-1)/3*3+(j+2)/3][a]++;
		}
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
			if(!x[i][j]||!y[i][j]||!z[i][j]){
				cout<<"Wrong"<<endl;
				return ;
			}
	cout<<"Right"<<endl;
}
/*
1 1 1 2 2 2 3 3 3
1 1 1 2 2 2 3 3 3 
1 1 1 2 2 2 3 3 3
*/
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
