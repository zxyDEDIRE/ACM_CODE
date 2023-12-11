/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int p[maxn];
int n,m;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n*2;i++)
		p[i]=i;
	for(int i=1;i<=m;i++)
	{
		char ch;int x,y;
		cin>>ch>>x>>y;
		if(ch=='D')
		{
			int fa=find(x);
			int fb=find(y);
			p[find(x+n)]=fb;
			p[find(y+n)]=fa;
		}
		else if(ch=='A')
		{
			int fa=find(x);
			int fb=find(y);
			int faa=find(x+n);
			int fbb=find(y+n);
			if(fa==fb||faa==fbb)cout<<"In the same gang."<<endl;
			else if(fa==fbb||faa==fb)cout<<"In different gangs."<<endl;
			else cout<<"Not sure yet."<<endl;
		}
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}