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
const int maxn=1e6;
void solve()
{
	int n;
	string str;
	bitset<1000>vis;
	cin>>n;
	cin>>str;
	int cnt=0;
	for(int i=0;i<str.size();i++)
	{
		cnt++;
		if(!vis[str[i]-'A'])
		{
			cnt++;
			vis[str[i]-'A']=1;
		}
	}
	cout<<cnt<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}