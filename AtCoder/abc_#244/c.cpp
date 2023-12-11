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
void solve()
{
	cin>>str;
	int l=0,r=str.size()-1;
	while(l<r)
	{
		if(str[l]!=str[r])
		{
			if(str[r]=='a')r--;
			else{
				cout<<"No"<<endl;
				return ;
			}
		}
		else l++,r--;
	}
	cout<<"Yes"<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

        solve();
    return 0;
}