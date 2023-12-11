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
int p[100];
void solve()
{
	for(int i=1;i<=8;i++)
		p[i]=i;
	do{
		for(int i=1;i<=8;i++)
			cout<<p[i]<<" ";
		cout<<endl;
	}while(next_permutation(p+1,p+9));
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}