/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
map<string,int>mp;
string f(string s)
{
	for(int i=0;i<s.size();i++)
	{
		char x=s[i];
		if(x>='a'&&x<='c')s[i]='2';
		else if(x>='d'&&x<='f')s[i]='3';
		else if(x>='g'&&x<='i')s[i]='4';
		else if(x>='j'&&x<='l')s[i]='5';
		else if(x>='m'&&x<='o')s[i]='6';
		else if(x>='p'&&x<='s')s[i]='7';
		else if(x>='t'&&x<='v')s[i]='8';
		else if(x>='w'&&x<='z')s[i]='9';
	}
	return s;
}
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		str=f(str);
		mp[str]++;
	}
	while(m--)
	{
		string str;
		cin>>str;
		if(mp.count(str))cout<<mp[str]<<endl;
		else cout<<0<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}