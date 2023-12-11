/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=1e3;
int a[N][N];
int b[N][N];
int n,m;
void f(int x,int y)
{
	for(int i=1;i<=n;i++)
		a[i][y]=1;
	for(int i=1;i<=m;i++)
		a[x][i]=1;
}
int A(int x,int y)
{
	int aa=0,bb=0;
	for(int i=1;i<=m;i++)
	{
		aa++;
		if(a[x][i])bb++;
	}
	for(int i=1;i<=n;i++)
	{
		aa++;
		if(a[i][y])bb++;
	}
	if(aa!=bb)return 1;
	else return 0;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>b[i][j];
			if(b[i][j]==0)
				f(i,j);
		}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==1&&A(i,j)==0){
				cout<<"NO"<<endl;
				return ;
			}
		}
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cout<<(a[i][j]^1)<<" ";
		cout<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}