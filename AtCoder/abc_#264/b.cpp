/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=100;
int mp[maxn][maxn];
int vis[maxn][maxn];
void init()
{
	for(int k=1;k<=8;k++)
	{
		int l=k;
		int r=15-k+1;
		int h=15-k+1;
		int d=k;
		int flag=0;
		if(k%2==1)flag=1;
		else flag=0;
		for(int i=l;i<=r;i++)
			for(int j=d;j<=h;j++)
				mp[i][j]=flag;
	}
}
void solve()
{
	int x,y;
	cin>>x>>y;

	init();
	if(mp[x][y])cout<<"black";
	else cout<<"white";

}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}