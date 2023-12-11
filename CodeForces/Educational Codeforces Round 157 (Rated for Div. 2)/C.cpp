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
string p[maxn];
map<pii,int>mp;
int n;
void solve()
{
	mp.clear();
	cin>>n;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		int l=p[i].size(),t=0;
		for(auto i:p[i])t+=i-'0';
		mp[{l,t}]++;
	}
	for(int i=1;i<=n;i++)
	{
		string str=p[i];
		int l=str.size(),t=0;
		for(auto i:str)t+=i-'0';
		int s_1=0,s_2=t,l_1=0,l_2=l;
		for(int i=0;i<l;i++)
		{
			s_1+=str[i]-'0';l_1++;
			s_2-=str[i]-'0';l_2--;
			if(l_1*2>=l){
				if(mp.count({l_1*2-l,s_1*2-t}))
					ans+=mp[{l_1*2-l,s_1*2-t}];
			}
			if(l_2*2>=l){
				if(mp.count({l_2*2-l,s_2*2-t}))
					ans+=mp[{l_2*2-l,s_2*2-t}];
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}