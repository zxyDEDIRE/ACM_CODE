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
string str;
bool solve()
{
	cin>>str;
	if(str[0]!='Y'&&str[0]!='y')return 0;
	if(str[1]!='E'&&str[1]!='e')return 0;
	if(str[2]!='S'&&str[2]!='s')return 0;
	return 1;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--){

        if(solve())cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}