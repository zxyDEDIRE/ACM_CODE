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
int p[maxn][11];
int t[maxn][11];
int s[11];
int n,m,tot;
void insert(int *p)
{
	int rt=0;
	for(int i=1;i<=m;i++)
	{
		if(!t[rt][p[i]])t[rt][p[i]]=++tot;
		rt=t[rt][p[i]];
	}
}
int query(int *p)
{
	int rt=0;
	for(int i=1;i<=m;i++)
	{
		if(!t[rt][p[i]])
			return i;
		rt=t[rt][p[i]];
	}
	return m;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>p[i][j];
	for(int x=1;x<=1;x++)
	{
		for(int y=1;y<=n;y++)
		{
			int *a=p[x];
			int *b=p[y];
			cout<<"y "<<y<<endl;
			for(int i=1;i<=m;i++)
				cout<<b[a[i]]<<" ";
			cout<<endl;
		}
	}
}
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
/*
3 9 1 8 5 7 4 10 2 6


3 9 1 7
*/