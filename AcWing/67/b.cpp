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
const int maxn=100;
int mp[maxn][maxn];
int n,m;
bool ok()
{
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=1;j<=m;j++)
			if(mp[i][j]!=j)
				cnt++;
		if(cnt>2)return 0;
	}
	cout<<"YES"<<endl;
	return 1;
}
bool doit(int x,int y)
{
	for(int i=1;i<=n;i++)
		swap(mp[i][x],mp[i][y]);
	if(ok())return 1;
	for(int i=1;i<=n;i++)
		swap(mp[i][x],mp[i][y]);
	return 0;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	if(ok())return ;
	for(int i=1;i<=m;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			if(doit(i,j))return ;
		}
	}
	cout<<"NO"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}