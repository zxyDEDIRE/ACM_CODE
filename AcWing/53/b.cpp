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
ll ans=0;
int n;
void solve()
{
	cin>>str;
	str="0"+str;
	n=str.size()-1;
	for(int i=1;i<=n;i++)
	{
		int x=str[i]-'0';
		int y=str[i-1]-'0';
		if(x%4==0)ans++;
		if((y*10+x)%4==0)ans+=i-1;
	}
	cout<<ans<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
	return 0;
}
/*
*/