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
		if(i%2==0)//xiao
		{
			if(str[i]=='a')str[i]='b';
			else str[i]='a';
		}
		else
		{
			if(str[i]=='z')str[i]='y';
			else str[i]='z';
		}
	}
	cout<<str<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}