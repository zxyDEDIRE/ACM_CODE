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
string str;
int num=0;
void dfs(int x,string str)
{
	if(x==9)
	{
		int a=0,b=0,cnt=0,flag=1;
		for(int i=0;i<str.size();i++)
		{
			if(str[i]=='(')a++,cnt++;
			else if(str[i]==')')b++,cnt--;
			if(cnt<0)flag=0;
		}
		if(a!=b)flag=0;
		if(flag)cout<<str<<endl,num++;
		return ;
	}
	dfs(x+1,str+'(');
	dfs(x+1,str+')');
}
void solve()
{
	dfs(1,"");
	cout<<num<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}