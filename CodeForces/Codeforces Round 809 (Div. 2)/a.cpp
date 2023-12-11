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
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	bitset<maxn>vis;
	for(int i=1;i<=n;i++)
	{
		int x=p[i];
		int y=m+1-p[i];
		if(x>y)swap(x,y);
		if(!vis[x])vis[x]=1;
		else vis[y]=1;
	}
	for(int i=1;i<=m;i++)
	{
		if(vis[i])cout<<"A";
		else cout<<"B";
	}
		
	cout<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}