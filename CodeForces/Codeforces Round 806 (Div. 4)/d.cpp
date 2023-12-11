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
map<string,int>mp;
string p[maxn];
int n;
void solve()
{
	cin>>n;
	mp.clear();
	for(int i=1;i<=n;i++)
		cin>>p[i],mp[p[i]]=1;
	for(int i=1;i<=n;i++)
	{
		int len=p[i].size();
		string a,b;
		int flag=0;
		for(int j=1;j<len;j++)
		{
			a=b="";
			for(int k=0;k<len;k++)
				if(k<j)a+=p[i][k];
				else b+=p[i][k];
			if(mp[a]&&mp[b])
			{
				flag=1;
				cout<<1;
				break;
			}
		}
		if(!flag)cout<<0;
	}
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
0123456
0123456
0123456
0123456
0123456
0123456
*/