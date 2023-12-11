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
string t="atcoder";
map<char,int>mp;
void solve()
{
	cin>>str;
	int ans=0;
	int fl=0;
	for(int i=0;i<t.size();i++)
	{
		int x;
		if(str[i]==t[i])continue;
		for(int j=i;j<str.size();j++)
			if(str[j]==t[i]){
				x=j;
				break;
			}
		for(int j=x;j>i;j--)
			swap(str[j],str[j-1]),ans++;
	}
	cout<<ans<<endl;
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
/*
catredo
*/