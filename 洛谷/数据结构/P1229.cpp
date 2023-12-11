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
string a,b;
struct node{
	int l,r;
}p[maxn];
ll ans=1;
void dfs(int x,string a,string b)
{
	//cout<<a<<endl;
	int len=a.size();
	if(len==1)return ;
	if(a[1]==b[len-2])
	{
		ans*=2;
		string aa,bb;
		for(int i=1;i<len;i++)
			aa+=a[i];
		for(int i=0;i<=len-2;i++)
			bb+=b[i];
		dfs(mp[a[0]],aa,bb);
	}
	else
	{
		string a_1,b_1;
		for(int i=0;i<len;i++)
		{
			a_1+=a[i+1];
			b_1+=b[i];
			if(b[i]==a[1])break;
		}
		dfs(a[1],a_1,b_1);



		string a_2,b_2;
		for(int i=len-1;i>=0;i--)
		{
			a_2+=a[i];
			b_2+=b[i-1];
			if(a[i]==b[len-2])break;
		}
		reverse(a_2.begin(),a_2.end());
		reverse(b_2.begin(),b_2.end());
		dfs(b[len-2],a_2,b_2);
	}
}
void solve()
{
	cin>>a>>b;
	int len=a.size();
	for(char i='a';i<='z';i++)
		mp[i]=i-'a'+1;
	dfs(mp[a[0]],a,b);
	cout<<ans<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
