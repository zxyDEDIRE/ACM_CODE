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
string str;
void solve()
{
	cin>>str;
	stack<pair<char,int>>s;
	for(auto i:str)
	{
		if(s.size()==0)s.push({i,0});
		else if(i=='A')
		{
			s.push({i,0});
		}
		else if(i=='B')
		{
			if(s.top().first=='A')
				s.push({i,1});
			else s.push({i,0});
		}
		else
		{
			if(s.top().first=='B'&&s.top().second==1)
			{
				s.pop();s.pop();
			}
			else s.push({i,0});
		}
	}
	vector<char>v;
	while(s.size()){
		v.push_back(s.top().first);
		s.pop();
	}
	reverse(v.begin(),v.end());
	for(auto i:v)
		cout<<i;
	cout<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}