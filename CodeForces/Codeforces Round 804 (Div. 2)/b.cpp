/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=100;
string mp[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<mp[i][j]<<" ";
		cout<<"\n";
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    for(int i=1;i<=20;i++)
    {
    	mp[0]+="1001";
    	mp[1]+="0110";
    	mp[2]+="0110";
    	mp[3]+="1001";
    }
    for(int i=0;i<=60;i+=4)
    {
    	mp[i]=mp[0];
    	mp[i+1]=mp[1];
    	mp[i+2]=mp[2];
    	mp[i+3]=mp[3];
    }
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}