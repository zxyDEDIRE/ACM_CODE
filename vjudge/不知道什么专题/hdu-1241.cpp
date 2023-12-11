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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
char mp[111][111];
int p[maxn];
int n,m;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
int f(int x,int y){
	return (x-1)*m+y;
}
void solve()
{
	for(int i=1;i<=n*m;i++)
		p[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]!='@')continue;
			for(int k=0;k<8;k++)
			{
				int x=i+dx[k];
				int y=j+dy[k];
				if(x<1||y<1||x>n||y>m)continue;
				if(mp[x][y]!='@')continue;
				int fa=find(f(x,y));
				int fb=find(f(i,j));
				if(fa!=fb)p[fa]=fb;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mp[i][j]=='@'&&f(i,j)==find(f(i,j)))
				cnt++;
	cout<<cnt<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	while(cin>>n>>m){
		if(n==0)break;
		solve();
	}
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}