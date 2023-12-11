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
	int n=str.size();
	if(n==1)cout<<"1 2"<<endl;
	else if(n==2)
	{
		if(str[0]==str[1])cout<<"2 8"<<endl;
		else cout<<"2 6"<<endl;
	}
	else
	{
		int flag=1;
		for(int i=0;i<n-1;i++)
			if(str[i]!=str[i+1])
				flag=0;
		if(flag)cout<<"2 4"<<endl;
		else cout<<"2 2"<<endl;
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
a.
.b
.*
..
.+
ab



.*
.a
..
a.
a*
aa
a+
.+


.*
.+

a*
a+
*/
