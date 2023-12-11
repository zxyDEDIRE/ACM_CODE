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
#include<stack>
#include<map>
#include<set>
using namespace std;
#define endl "\n"
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int maxn=1e3;
int dfn[maxn],low[maxn],indx;
int in[maxn],out[maxn];
vector<int>v[maxn];
bitset<maxn>vis;
int col[maxn],tot;
stack<int>s;
int n;
void tarjan(int x)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	vis[x]=1;
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x])
	{
		int y;
		++tot;
		do{
			y=s.top();s.pop();
			vis[y]=0;
			col[y]=tot;
		}while(x!=y);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		while(cin>>x&&x){
			v[i].push_back(x);
		}
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int x=1;x<=n;x++)
	{
		for(int i=0;i<v[x].size();i++)
		{
			int y=v[x][i];
			if(col[x]!=col[y])
			{
				in[col[y]]++;
				out[col[x]]++;
			}
		}
	}
	int cnt=0;
	int A=0,B=0;
	for(int i=1;i<=tot;i++)
	{
		if(!in[i])cnt++;
		if(!in[i])A++;
		if(!out[i])B++;
	}
	cout<<cnt<<endl;
	if(tot==1)cout<<0<<endl;
	else cout<<max(A,B)<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
        solve();
    return 0;
}
/*
4
2 0
1 0
4 0
3 0
*/