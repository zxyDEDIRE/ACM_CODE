#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define endl '\n'
string s,t;
void solve()
{
	if(s==t)cout<<"Equal"<<endl;
	else
	{
		int flag=0;
		if(s[0]==t[0]&&s.back()==t.back())
			flag=1;
		sort(s.begin(),s.end());
		sort(t.begin(),t.end());
		if(s==t&&flag)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	while(cin>>s>>t)
		solve();
	return 0;
}