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
const ull mod=212370440130137957ll;
const ull prime=233317;
const ull base=131;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
map<ull,string>mpa;
map<ull,int>mp;
int n;
ull get_hash(string &s)
{
	ull ans=0;
	for(int i=0;i<s.size();i++)
		ans=(ans*base+(ull)s[i])%mod+prime;
	return ans;
}
void solve()
{
	// cin>>n;
	n=1234;
	cout<<n<<endl;
	// for(int i=1;i<=n;i++)
	// {
	// 	int k;cin>>k;
	// 	while(k--){
	// 		string str;
	// 		cin>>str;
	// 		mp[get_hash(str)]++;
	// 		mpa[get_hash(str)]=str;
	// 	}
	// }
	// vector<string>v;
	// for(auto [x,y]:mp)
	// 	if(y==n)
	// 		v.push_back(mpa[x]);
	// sort(v.begin(),v.end());
	// cout<<v.size()<<endl;
	// for(auto x:v)
	// 	cout<<x<<endl;

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}