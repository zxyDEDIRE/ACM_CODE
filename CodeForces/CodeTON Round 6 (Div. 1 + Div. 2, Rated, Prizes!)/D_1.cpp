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
struct node{
	int x,id,cnt;
}p[maxn];
int n,k;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].x,p[i].id=i,p[i].cnt=0;
	cin>>k;
	stack<node>s;
	vector<node>v;
	for(int i=1;i<=n;i++)
	{
		if(s.empty())s.push(p[i]);
		else
		{
			while(!s.empty()&&p[i].x<=s.top().x)
				s.pop();
			s.push(p[i]);
		}
	}
	while(!s.empty())
		v.push_back(s.top()),s.pop();
	reverse(v.begin(),v.end());

	v[0].cnt+=k/v[0].x;
	k%=v[0].x;

	for(int i=1;i<v.size();i++)
	{
		auto &[x,id,cnt]=v[i];
		auto &[_x,_id,_cnt]=v[i-1];

		int now=k/(x-_x);
		now=min(now,_cnt);
		cnt+=now;
		_cnt-=now;
		k-=now*(x-_x);
	}
	for(auto [x,id,cnt]:v)
		p[id].cnt+=cnt;
	for(int i=n-1;i>=1;i--)
		p[i].cnt+=p[i+1].cnt;
	for(int i=1;i<=n;i++)
		cout<<p[i].cnt<<" ";cout<<endl;
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