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
ll n,k;
void solve()
{
	cin>>str>>k;
	n=str.size();
	ll l=0,r=n-1,ans=r;

	auto check=[&](ll mid)->bool{
		ll l=n-mid;
		ll r=n;
		ll sum=(l+r)*(r-l+1)/2;
		return sum>=k;
	};

	while(l<r-1)
	{
		ll mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid;
		else r=mid;
	}
	while(check(ans-1))ans--;
	ll _r=n;
	ll _l=(n-ans)+1;
	ll len=(_l+_r)*(_r-_l+1)/2;
	ll pos=k-len;

	deque<char>q;
	for(auto i:str)
	{
		if(q.empty())
		{
			// cout<<"pb "<<i<<endl;
			q.push_back(i);
		}
		else
		{
			while(ans&&!q.empty()&&q.back()>i)
			{
				ans--;
				q.pop_back();
			}
			q.push_back(i);
		}
	}
	vector<char>v;
	while(q.size())
	{
		v.push_back(q.front());
		q.pop_front();
	}
	cout<<v[pos-1];



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
/*
0
1
2
3
4
5

abcd 4
abc 3
ab 2


cdabda
cabda
abda
aba

*/