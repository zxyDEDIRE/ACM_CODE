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
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
string str;
vector<int>v[100];
void solve()
{
	cin>>str;
	for(int i=0;i<26;i++)
		v[i].clear();
	for(int i=0;i<str.size();i++)
		v[str[i]-'a'].push_back(i+1);
	int s=str[0]-'a';
	int t=str.back()-'a';
	cout<<abs(s-t)<<" ";
	if(s<=t)
	{
		int ans=0;
		for(int i=s;i<=t;i++)
			ans+=v[i].size();
		cout<<ans<<endl;
		for(int i=s;i<=t;i++)
			for(auto j:v[i])
				cout<<j<<" ";
		cout<<endl;
	}
	else
	{
		int ans=0;
		for(int i=s;i>=t;i--)
			ans+=v[i].size();
		cout<<ans<<endl;

		for(int i=s;i>=t;i--)
			for(auto j:v[i])
				cout<<j<<" ";
		cout<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}