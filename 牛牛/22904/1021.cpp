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
map<string,int>mp;
int p[maxn];
int n,m,cnt;
int find(int r)
{
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		p[i]=i;
		string str;
		cin>>str;
		mp[str]=++cnt;
	}
	while(m--)
	{
		int op;
		string s,t;
		cin>>op>>s>>t;
		if(op==1)
		{
			int fa=find(mp[s]);
			int fb=find(mp[t]);
			if(fa!=fb)p[fa]=fb;
		}
		else
		{
			int fa=find(mp[s]);
			int fb=find(mp[t]);
			if(fa==fb)cout<<1<<"\n";
			else cout<<"0"<<"\n";
		}
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

        solve();
    return 0;
}