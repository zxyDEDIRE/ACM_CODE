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
int p[maxn];
int n,m;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	while(1)
	{
		cin>>n;
		if(n==0)return ;
		cin>>m;
		for(int i=1;i<=n;i++)
			p[i]=i;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			int fa=find(x);
			int fb=find(y);
			if(fa!=fb)
			{
				p[fa]=fb;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(p[i]==i)
				cnt++;
			cout<<cnt-1<<endl;
		}

	}
	signed main(){
		ios::sync_with_stdio(false);
		cin.tie(nullptr);cout.tie(nullptr);
		solve();
		return 0;
	}