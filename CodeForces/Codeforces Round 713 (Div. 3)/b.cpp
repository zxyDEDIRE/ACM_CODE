/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
char mp[500][500];
int n,m;
vector<pii>v;
void solve()
{
	cin>>n;
	v.clear();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>mp[i][j];
			if(mp[i][j]=='*')v.push_back({i,j});
		}
	}
	if(v[0].first==v[1].first)
	{
		int xx=v[0].first;
		if(xx>1)mp[xx-1][v[0].second]=mp[xx-1][v[1].second]='*';
		else mp[xx+1][v[0].second]=mp[xx+1][v[1].second]='*';
	}
	else if(v[0].second==v[1].second)
	{
		int xx=v[0].second;
		if(xx>1)mp[v[0].first][xx-1]=mp[v[1].first][xx-1]='*';
		else mp[v[0].first][xx+1]=mp[v[1].first][xx+1]='*';
	}
	else
	{
		int a=min(v[0].x,v[1].x);
		int aa=max(v[0].x,v[1].x);
		int b=min(v[0].y,v[1].y);
		int bb=max(v[0].y,v[1].y);
		mp[a][b]=mp[a][bb]=mp[aa][b]=mp[aa][bb]='*';
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<mp[i][j];
		cout<<endl;
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}