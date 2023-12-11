/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
string str;
void YES(){
	cout<<"Yes"<<endl;
}
void NO(){
	cout<<"NO"<<endl;
}
void solve()
{
	cin>>str;
	int n=str.size();
	int a=0,b=0,c=0;
	 for(int i=0;i<str.size();i++){
		if(str[i]=='r')a++;
		if(str[i]=='e')b++;
		if(str[i]=='d')c++;
	}
	a=n/3-a;
	b=n/3-b;
	c=n/3-c;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='?')
		{
			if(a)str[i]='r',a--;
			else if(b)str[i]='e',b--;
			else if(c)str[i]=='d',c--;
		}
	}
	cout<<str<<endl;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='r')a++;
		if(str[i]=='e')b++;
		if(str[i]=='d')c++;
		if(!(a>=b&&b>=c))return NO();
	}
	return YES();


}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}