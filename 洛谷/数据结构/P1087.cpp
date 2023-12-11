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
struct node{
	string str;
	int l,r;
}p[maxn];
string str;
void dfs(int x,string str)
{
	p[x].str=str;
	string a,b;
	int len=str.size();
	if(len==1)return ;
	for(int i=0;i<len;i++)
	{
		if(i<len/2)a+=str[i];
		else b+=str[i];
	}
	p[x].l=x*2;
	dfs(x*2,a);
	p[x].r=x*2+1;
	dfs(x*2+1,b);
}
void f(int x)
{
	if(p[x].str.size()>1)
	{
		f(x*2);
		f(x*2+1);
	}
	string str=p[x].str;
	int a=0,b=0,len=str.size();
	for(int i=0;i<len;i++)
		if(str[i]=='0')a++;
		else b++;
	if(a&&!b)cout<<"B";
	else if(!a&&b)cout<<"I";
	else cout<<"F";
}
void solve()
{
	int n;
	cin>>n;
	cin>>str;
	dfs(1,str);
	f(1);
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
	return 0;
}