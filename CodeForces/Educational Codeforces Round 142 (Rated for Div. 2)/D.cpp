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
const int N=5e4+10;
int t[maxn][11],indx;
int p[N][11];
int s[11];
int n,m;
void insert()
{
	int rt=0;
	for(int i=1;i<=m;i++)
	{
		if(!t[rt][s[i]])t[rt][s[i]]=++indx;
		rt=t[rt][s[i]];
	}
}
int query(int x) 
{
	int rt=0;
	for(int i=1;i<=m;i++)
	{
		if(!t[rt][p[x][i]])
			return i-1;
		rt=t[rt][p[x][i]];
	}
	return m;
}
void clear()
{
	for(int i=0;i<=indx;i++)
		for(int j=0;j<=10;j++)
			t[i][j]=0;
	indx=0;
}
void solve()
{
	cin>>n>>m;
	clear();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cin>>p[i][j];
		for(int j=1;j<=m;j++)
			s[p[i][j]]=j;
		insert();
	}
	for(int i=1;i<=n;i++)
		cout<<query(i)<<" ";
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\a.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\b.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
 // fclose(stdin);
 // fclose(stdout);
	return 0;
}
/*
1
27 5
3 2 4 5 1 
1 3 2 4 5 
2 5 3 1 4 
4 1 2 5 3 
3 4 1 5 2 
4 2 3 5 1 
3 5 1 2 4 
5 4 3 1 2 
4 2 3 5 1 
4 5 3 1 2 
4 1 3 5 2 
4 2 1 5 3 
5 1 2 4 3 
5 3 4 1 2 
5 4 1 2 3 
4 2 5 1 3 
4 1 2 5 3 
4 2 5 1 3 
1 3 5 2 4 
1 4 2 3 5 
1 5 4 2 3 
2 1 4 5 3 
4 5 2 3 1 
2 5 1 4 3 
3 1 5 4 2 
4 3 1 5 2 
1 3 4 2 5 

2 5 5 2 5 2 5 1 2 5 5 2 1 5 1 5 2 5 2 5 1 2 5 5 5 1 5 
*/