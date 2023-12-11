/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int n;
int f(int x)
{
	int ans=0;
	while(x)
	{
		ans+=x%10;
		x/=10;
	}
	return ans;
}
void solve()
{
	cin>>n;
	while(n>10)n=f(n);
	cout<<n<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

        solve();
    return 0;
}