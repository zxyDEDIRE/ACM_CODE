#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
void solve()
{
	int  n;
	cin>>n;
	if(n==0){
		cout<<0<<endl;
		return ;
	}
	int fl=(n<0)?1:0;
	n=abs(n);
	vector<int>v;
	while(n){
		v.push_back(n%2);
		n>>=1;
	}
	reverse(v.begin(),v.end());
	if(fl)cout<<"-";
	for(auto i:v)
		cout<<i;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}