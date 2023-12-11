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
ll n;
void solve()
{
	cin>>n;
	if(n%2==0)
	{
		cout<<(n/2-1)<<" "<<(n/2)<<" "<<1<<endl;
	}
	else
	{
		n--;
		for(int i=n-2;i>1;i--)
		{
			if(__gcd(i,n-i)==1)
			{
				cout<<i<<" "<<n-i<<" "<<1<<endl;
				return ;
			}
		}
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
1 5 5
*/