#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;

int mp[111][111];
int in[111];//入度
int n,m;

void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		mp[x][y]=1;
		in[y]++;
	}


	//队列
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i);

	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=1;i<=n;i++)
		{
			if(!mp[x][i])continue;
			in[i]--;
			if(!in[i])
				q.push(i);
		}
	}

}
signed main(){
		solve();
	return 0;
}