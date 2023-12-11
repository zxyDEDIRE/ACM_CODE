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
const int INF=0x3f3f3f3f;
const int maxn=1e6;
string str;
void solve()
{
	cin>>str;

	int l=0,r=str.size()-1,t=l;
	while(str[l]==0&&l<str.size())l++;
	while(str[r]==1&&r>=0)r--;
	while(l<r)
	{

	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}
/*
01101100000000101010
01010100000000001111
00000000001010101111
*/