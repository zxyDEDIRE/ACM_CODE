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
void solve()
{
	cin>>str;
	int cnt=0,s=0;
	str[0]='(';
	str.back()=')';
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='(')s++;
		if(str[i]==')')s--;
		if(str[i]=='?')cnt++;
		if(cnt+s==0)cnt=0,s=0;
		if(s<0)
		{
			cnt--;
			s++;
		}
	}
	if(abs(s)==cnt)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
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