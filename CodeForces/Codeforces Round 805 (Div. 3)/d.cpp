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
vector<int>v[100];
bitset<maxn>vis;
int n;
void solve()
{
	cin>>str>>n;
	vis.reset();
	for(int i=1;i<=30;i++)v[i].clear();
	int ans=0;
	for(int i=0;i<str.size();i++)
	{
		int t=str[i]-'a'+1;
		ans+=t;
		v[t].push_back(i);
	}
	int j=26;
	while(ans>n)
	{
		int flag=0;
		for(int i=0;i<v[j].size();i++)
		{
			int x=v[j][i];
			vis[x]=1;
			ans-=j;
			if(ans<=n)
			{
				flag=1;
				break;
			}
		}
		j--;
		if(flag)break;
	}
	for(int i=0;i<str.size();i++)
		if(!vis[i])cout<<str[i];
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