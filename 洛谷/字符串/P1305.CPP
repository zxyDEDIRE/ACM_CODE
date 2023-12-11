/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
bitset<maxn>vis;
map<char,int>mp;
struct node{
	char ch;
	int l,r;
}p[maxn];
int n,cnt;
void dfs(int x)
{
	cout<<p[x].ch;
	if(p[x].l)dfs(p[x].l);
	if(p[x].r)dfs(p[x].r);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		if(!vis[str[0]-'a'])
		{
			vis[str[0]-'a']=1;
			mp[str[0]]=++cnt;
			p[mp[str[0]]].ch=str[0];
		}
		if(str[1]!='*')
		{
			if(!vis[str[1]-'a'])
			{
				vis[str[1]-'a']=1;
				mp[str[1]]=++cnt;
				p[mp[str[1]]].ch=str[1];
			}
			p[mp[str[0]]].l=mp[str[1]];
		}
		if(str[2]!='*')
		{
			if(!vis[str[2]-'a'])
			{
				vis[str[2]-'a']=1;
				mp[str[2]]=++cnt;
				p[mp[str[2]]].ch=str[2];
			}
			p[mp[str[0]]].r=mp[str[2]];
		}
	}
	dfs(1);
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}