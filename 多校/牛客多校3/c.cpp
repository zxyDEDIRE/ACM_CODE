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
string p[maxn];
int n;
void solve()
{
	cin>>n;
	string a="101",b="10";

	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n);
	for(int i=1;i<=n;i++)
		cout<<p[i];
	cout<<endl;
}
int main()
{	
;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}