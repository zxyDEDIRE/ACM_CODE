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
int h=21,m=0;
void solve()
{
	int n;
	cin>>n;
	m+=n;
	h+=m/60;
	m%=60;
	cout<<h;
	cout<<":";
	if(m<10)cout<<0<<m<<endl;
	else cout<<m<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}