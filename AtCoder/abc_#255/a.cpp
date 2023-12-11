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
int p[5][5];
int x,y;
void solve()
{
	cin>>x>>y;
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
			cin>>p[i][j];
	cout<<p[x][y]<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

        solve();
    return 0;
}