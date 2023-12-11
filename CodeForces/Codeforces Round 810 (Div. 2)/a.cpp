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
int p[maxn];
int n;
void solve()
{
	cin>>n;
	cout<<n<<" ";
	for(int i=1;i<n;i++)
		cout<<i<<" ";
	cout<<endl;
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
1 2 3 4 5
2 1 5 3 4
1 2 3 4 5 6 7
1 2 3 4 7 5 6
1 2 3
3 1 2
*/