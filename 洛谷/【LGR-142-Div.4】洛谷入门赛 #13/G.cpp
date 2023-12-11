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
char mp[111][111];
int n,m;
bool check(int x,int y,int k)
{
	char ch=mp[x][y];
	for(int i=0;i<=4;i++)
	{
		int xx=x+dx[k]*i;
		int yy=y+dy[k]*i;
		if(xx<1||yy<1||xx>n||yy>m)return 0;
		if(mp[xx][yy]!=ch)return 0;
	}
	return 1;
}
void solve()
{
	cin>>n>>m;
	int cnt_1=0,cnt_2=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			if(mp[i][j]=='*')cnt_1++;
			else if(mp[i][j]=='$')cnt_2++;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<8;k++)
				if(mp[i][j]!='~'&&check(i,j,k)){
					if(mp[i][j]=='*')cout<<"Pleasing!"<<endl;
					else cout<<"zylwins!"<<endl;
					return ;
				}
	if(cnt_1>cnt_2)cout<<"Z"<<endl;
	else cout<<"W"<<endl;

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