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
int a[maxn];
void solve()
{
	map<int,int>mp;
	mp.clear();
	int p[3],cnt=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a[i]=x;
		mp[x]++;
		if(mp[x]==1)p[++cnt]=i;
	}
	if(mp[a[p[1]]]==1)cout<<p[1]<<endl;
	else cout<<p[2]<<endl;
}
signed main(){
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
6
4
..*.
....
*...
....
2
*.
.*
2
.*
.*
3
*.*
...
...
5
.....
..*..
.....
.*...
.....
4
....
....
*...
*...

*/