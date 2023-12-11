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
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int t[maxn][33],indx;
int num[maxn];
int n,q;
void init()
{
	for(int i=0;i<=indx;i++)
	{
		num[i]=0;
		for(int j=0;j<70;j++)
			t[i][j]=0;
	}
	indx=0;
}
int get_num(char x)
{
	if(x>='a'&&x<='z')
		return x-'a';
	else if(x=='.')return 27;
	else return 28;
}
void insert(string &str)
{
	int rt=0;
	for(int i=0;i<str.size();i++)
	{
		int c=get_num(str[i]);
		if(!t[rt][c])
			t[rt][c]=++indx;
		rt=t[rt][c];
		num[rt]++;
	}
}
int query(string &str)
{
	int rt=0,ans=0,pre=0;
	for(int i=0;i<str.size();i++)
	{
		int c=get_num(str[i]);
		if(!t[rt][c])
			return 0;
		rt=t[rt][c];
		if(num[rt]!=pre)ans++,pre=num[rt];
		if(num[rt]==1)break;
	}
	return ans;
}
string p[maxn];
void solve()
{
	cin>>n;
	init();

	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		insert(p[i]);
	}
	for(int i=1;i<=n;i++)
		cout<<query(p[i])<<endl;

}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}