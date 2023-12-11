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
vector<int>v[100];
string str;
int n,q;
void solve()
{
	cin>>n>>q>>str;
	for(int i=0;i<str.size();i++)
		v[str[i]-'a'].clear();
	for(int i=0;i<str.size();i++)
		v[str[i]-'a'].push_back(i);
	while(q--)
	{
		int last=-1;
		int flag=1;
		string t;
		cin>>t;
		for(int i=0;i<t.size();i++)
		{
			int fl=upper_bound(v[t[i]-'a'].begin(),v[t[i]-'a'].end(),last)-v[t[i]-'a'].begin();
			if(fl>=v[t[i]-'a'].size()&&v[t[i]-'a'][fl]<=last)
			{
				flag=0;
				break;
			}
			last=v[t[i]-'a'][fl];
		}
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
