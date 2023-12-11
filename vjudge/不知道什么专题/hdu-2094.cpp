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
map<string,int>mp;
vector<int>v[maxn];
int in[maxn],p[maxn];
int n,cnt;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	while(cin>>n&&n)
	{
		for(int i=1;i<=n;i++)
			in[i]=0;
		mp.clear();
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			string a,b;
			cin>>a>>b;
			if(!mp[a])mp[a]=++cnt;
			if(!mp[b])mp[b]=++cnt;
			in[mp[b]]++;
		}
		int num=0;
		for(int i=1;i<=cnt;i++)
			if(in[i]==0)num++;
		if(num!=1)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}