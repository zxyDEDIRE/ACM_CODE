/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
string str;
void solve()
{
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		int x=str[i]-'0';
		int y=9-x;
		if(i==0&&x==9)cout<<9;
		else cout<<min(x,y);
		
	}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
	return 0;
}