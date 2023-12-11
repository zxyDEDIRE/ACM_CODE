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
struct node{
	bool mp[111][111];
	int n,m;
}p[10];
bool vis[111][111];
int n,m;

bool check(int x1,int y1,int x2,int y2)
{
	memset(vis,0,sizeof(vis));
	
	for(int i=1;i<=p[1].n;i++)
		for(int j=1;j<=p[1].m;j++){
			int x=i+x1;
			int y=j+y1;
			if(x>=1&&y>=1&&x<=n&&y<=m){
				vis[x][y]|=p[1].mp[i][j];
			}
			else if(p[1].mp[i][j]==1)return 0;
		}
	for(int i=1;i<=p[2].n;i++)
		for(int j=1;j<=p[2].m;j++){
			int x=i+x2;
			int y=j+y2;
			if(x>=1&&y>=1&&x<=n&&y<=m){
				vis[x][y]|=p[2].mp[i][j];
			}
			else if(p[2].mp[i][j]==1)return 0;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(vis[i][j]!=p[3].mp[i][j])
				return 0;
	return 1;
}
bool A(int x,int y)
{
	for(int i=-11;i<=11;i++)
		for(int j=-11;j<=11;j++)
			if(check(x,y,i,j))
				return 1;
	return 0;
}
void solve()
{
	memset(p[1].mp,0,sizeof(p[1].mp));
	for(int T=1;T<=3;T++)
	{
		cin>>p[T].n>>p[T].m;
		for(int i=1;i<=p[T].n;i++)
			for(int j=1;j<=p[T].m;j++){
				char x;cin>>x;
				if(x=='#')p[T].mp[i][j]=1;
				else p[T].mp[i][j]=0;
			}
	}
	n=p[3].n;
	m=p[3].m;
	for(int i=-11;i<=11;i++)
		for(int j=-11;j<=11;j++)
			if(A(i,j)){
				cout<<"Yes"<<endl;
				return ;
			}

	cout<<"No"<<endl;

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
/*
1 1

*/