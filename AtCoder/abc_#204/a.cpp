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
void solve()
{
	int p[4];
	for(int i=1;i<=2;i++)
		cin>>p[i];
	sort(p+1,p+3);
	if(p[1]==p[2])cout<<p[1]<<endl;
	else
	{
		if(p[1]!=0)cout<<0<<endl;
		else if(p[2]!=2)cout<<2<<endl;
		else  cout<<1<<endl;
	}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
	return 0;
}