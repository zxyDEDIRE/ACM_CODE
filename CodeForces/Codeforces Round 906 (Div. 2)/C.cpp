#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<char,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<pii>s,t;
string str;
int n;
void solve()
{
	cin>>n>>str;
	s.clear();
	t.clear();
	if(n&1){
		cout<<-1<<endl;
		return ;
	}
	deque<pii>st;
	for(auto i:str)
		st.push_back({i,0});
	int cnt=0;
	while(st.size())
	{
		if(cnt==300)break;
		pii a=st.front();
		pii b=st.back();
		if(a.first!=b.first)
		{
			s.push_back(a);
			t.push_back(b);
			st.pop_front();
			st.pop_back();
		}
		else if(a.first=='0')
		{
			cnt++;
			st.push_back({'0',1});
			st.push_back({'1',0});
		}
		else if(a.first=='1')
		{
			cnt++;
			st.push_front({'1',0});
			st.push_front({'0',1});
		}
	}
	if(st.size()){
		cout<<-1<<endl;
		return ;
	}
	reverse(t.begin(),t.end());
	for(auto i:t)
		s.push_back(i);
	vector<int>ans;
	for(int i=0;i<s.size();i++)
	{
		if(s[i].second==1)
			ans.push_back(i);
	}
	cout<<ans.size()<<endl;
	for(auto i:ans)
		cout<<i<<" ";cout<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}