#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;

	
bool mp[111][111];
int n;

void solve()
{
	// n条边
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;

		// 若单向边
		mp[x][y]=1;

		//若双向边
		mp[x][y]=mp[y][x]=1;

	}

}
signed main(){
		solve();
	return 0;
}