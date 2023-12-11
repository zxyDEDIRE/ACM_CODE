/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<char,int>;
const int maxn=1e6;
vector<string>v[maxn];
bitset<maxn>vis;
string str,t;
int p[maxn];
int n,m;
void solve()
{
	cin>>n>>m>>str;
	stack<pii>st;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='(')
		{
			st.push({'(',i});
		}
		else if(str[i]==')')
		{
			auto [ch,x]=st.top();
			if(ch=='(')
			{
				p[x]=i;
				p[i]=x;
				st.pop();
			}
		}
	}
	int len=n;
	for(int i=0;i<n;i++)
	{
		if(len==m)break;
		if(vis[i])continue;
		if(len>m)
		{
			vis[i]=1;
			vis[p[i]]=1;
			len-=2;
		}
	}
	for(int i=0;i<n;i++)
		if(!vis[i])cout<<str[i];
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}