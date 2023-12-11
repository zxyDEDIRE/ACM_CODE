/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
string str;
int l,r;
void solve()
{
	cin>>l>>r;
	cin>>str;
	int len=str.size();
	
	str=" "+str;
	for(int i=1;i<l;i++)
		cout<<str[i];
	for(int i=r;i>=l;i--)
		cout<<str[i];
	for(int i=r+1;i<=len;i++)
		cout<<str[i];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

        solve();
    return 0;
}