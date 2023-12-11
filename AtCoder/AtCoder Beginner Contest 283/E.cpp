/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=1111;
int mp[N][N];
int p[maxn];
int n,m,ans;
bool f(int x,int y)
{
	for(int k=0;k<4;k++)
	{
		int xx=x+dx[k];
		int yy=y+dy[k];
		if(xx>0&&xx<=n&&yy>0&&yy<=m)
		{
			if(mp[xx][yy]==mp[x][y])
				return 1;
		}
	}
	return 0;
}
bool check(int x)
{
	int flag=0;
		for(int j=1;j<=m;j++)
			if(f(x,j)==0){
				flag=1;
				break;
			}
	return flag;
}
void doit(int x)
{
	for(int j=1;j<=m;j++)
		mp[x][j]=1-mp[x][j];
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	for(int i=1;i<=n;i++)
		if(check(i))
			p[i]=1;
	for(int i=1;i<=n;i++)
	{
		if(!p[i])continue;
		if(i+2<=n&&p[i]&&p[i+1]&&p[i+2])
		{
			doit(i+1);
			ans++;
			p[i]=p[i+1]=p[i+2]=0;
		}else {
			ans++;
			p[i]=p[i+1]=0;
			doit(i);
		}
	}
	for(int i=1;i<=n;i++)
		if(check(i)){
			cout<<-1<<endl;
			return ;
		}
	cout<<ans<<endl;

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
/*
4 4
3 3
1 1 0
0 1 
1 0 0

1 9 8 7 6 5 4 3 2 
*/