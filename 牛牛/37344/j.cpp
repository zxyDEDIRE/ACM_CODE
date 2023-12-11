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
map<ll,int>mp;
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			mp[p[i]+p[j]]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp[p[i]-p[j]]||mp[[p[j]-p[i]]]){
				cout<<"Yes"<<endl;
				return ;
			}
		}
	}
	cout<<"No"<<endl;
	return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}