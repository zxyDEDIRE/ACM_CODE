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
const int maxn=1111;
int mp[maxn][maxn];
int p[1000000];
int n,m;
int f(int x,int y){
	return (x-1)*m+y;
}
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	for(int i=1;i<=f(n,m);i++)
		p[i]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=0;k<8;k++)
			{
				int x=i+dx[k];
				int y=j+dy[k];
				if(x<1||y<1||x>n||y>m)continue;
				int fa=f(x,y);
				int fb=f(i,j);
				if(fa==fb)continue;
				if(mp[x][y]>mp[i][j])
					p[fb]=fa;
				else p[fa]=fb;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=f(n,m);i++)
		if(p[i]==i)
			cnt++;
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("(%d:%d) ",f(i,j),p[f(i,j)]);
		cout<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3 7
0 0 0 1 1 1 0
0 1 2 2 1 1 0
0 1 1 1 2 1 0
*/