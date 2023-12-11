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

	ll sum=0;
	ll k=0;
	int n=str.size();
	vector<int>v;

	for(int i=0;i<str.size();i++)
		sum+=str[i]-'0';

	for(int i=n-1;i>=0;i--)
	{
		k+=sum;
		v.push_back(k%10);
		k/=10;
		sum-=str[i]-'0';
	}
	if(k)v.push_back(k);
	reverse(v.begin(),v.end());
	for(auto i:v)
		cout<<i;
	cout<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}
/*
5 3 2 4 6 1
1 2 3 4 5 6
1 2 3 4 5 6

5 6 1 5

1 5
5 6
1 2
2 3

*/