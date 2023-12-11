/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long 
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
set<int>s;
unordered_map<int,int>mp;
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		s.insert(x);
		mp[x]++;
	}
	int cnt=0;
	while(s.size()>1)
	{
		int x=*s.begin();
		int y=*s.rbegin();
		if(mp[y]==1)s.erase(y);
		else mp[y]--;
		if(y%x)
		{
			if(mp[y%x])mp[y%x]++;
			else s.insert(y%x),mp[y%x]++;
		}
		cnt++;
		for(auto i:s)
			cout<<i<<" ";cout<<endl;
	}
	cout<<cnt<<endl;
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}