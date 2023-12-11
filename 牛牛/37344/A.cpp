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
const int maxn=1e6;
int dx[10],dy[10];
bitset<111>vis[111];
int d1,d2;
void solve()
{
	cin>>d1>>d2;
	dx[0]=dx[1]=dy[4]=dy[6]=d1;
	dx[2]=dx[3]=dy[5]=dy[7]=-d1;
	dy[0]=dy[2]=dx[4]=dx[5]=d2;
	dy[1]=dy[3]=dx[6]=dx[7]=-d2;

	queue<pii>q;
	q.push({1,1});
	vis[1][1]=1;
	while(!q.empty())
	{
		auto [x,y]=q.front();q.pop();
		for(int i=0;i<8;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||xx>100||yy<1||yy>100||vis[xx][yy])continue;
			vis[xx][yy]=1;
			q.push({xx,yy});
		}
	}
	int flag=0;
	for(int i=1;i<=100;i++)
		for(int j=1;j<=100;j++)
			if(vis[i][j]==0)flag=1;

	if(flag==0)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}
/*
:https://paste.ubuntu.com/p/wCh98N2xwS/

1 -1 0 0 1 -1 1 -1 
0 0 1 -1 1 -1 - 1
*/