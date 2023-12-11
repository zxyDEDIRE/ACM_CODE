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
const int maxn=1e6;
string str;
void solve()
{
	cin>>str;
	bitset<100>vis;

	int cnt=0;
	int ans=1;
	for(int i=0;i<str.size();i++)
	{
		if(!vis[str[i]-'a'])
		{
			cnt++;
			if(cnt==4)
			{
				vis.reset();
				vis[str[i]-'a']=1;
				cnt=1;
				ans++;
			}
			else vis[str[i]-'a']=1;
		}
	}
	cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}