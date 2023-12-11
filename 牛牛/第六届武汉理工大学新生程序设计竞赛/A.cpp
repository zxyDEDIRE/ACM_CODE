#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
map<string,vector<string>>mp;
int n,q;
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string str,now;
		cin>>str;
		for(auto x:str)
			if(x>='A'&&x<='Z')
				now=now+x;
		mp[now].push_back(str);
	}
	while(q--)
	{
		string x;
		cin>>x;
		if(!mp.count(x))cout<<0<<endl;
		else
		{
			cout<<mp[x].size()<<endl;
			for(auto i:mp[x])
				cout<<i<<endl;
		}
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}