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
const int N=1024*3+100;
char mp[N][N];
int vis[N][N];
int n;
void dfs(int x1,int x2,int y1,int y2,int flag)
{
	if((x2-x1+1)==6&&(y2-y1+1)==6)
	{
		for(int i=x1;i<=x2;i++)
			for(int j=y1;j<=y2;j++)
				if(flag==1)mp[i][j]='*';
				else mp[i][j]='.';
		for(int i=x1+3;i<=x2;i++)
			for(int j=y1+3;j<=y2;j++)
				if(flag==1)mp[i][j]='.';
				else mp[i][j]='*';
		return ;
	}
	int mid_1=(x1+x2)/2;
	int mid_2=(y1+y2)/2;
	dfs(x1,mid_1,    y1,mid_2,flag^1);
	dfs(mid_1+1,x2,  y1,mid_2,flag^1);
	dfs(x1,mid_1,    mid_2+1,y2,flag^1);
	dfs(mid_1+1,x2,  mid_2+1,y2,flag);
}
void solve()
{
	cin>>n;
	int len=3*(1<<n);
	dfs(1,len,1,len,1);
	for(int i=1;i<=len;i++){
		for(int j=1;j<=len;j++)
			cout<<mp[i][j];
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
/*
7+12/2
19/2=9
789

*/