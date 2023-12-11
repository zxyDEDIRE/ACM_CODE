#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define T string::npos
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
int n;
void solve()
{
	cin>>n;getchar();
	ll ans=0;
	while(n--)
	{
		string str;
		getline(cin,str);
		int x,y=1;
		if(str.find("bool")!=T||str.find("char")!=T)x=1;
		else if(str.find("int")!=T||str.find("float")!=T)x=4;
		else if(str.find("long long")!=T||str.find("double")!=T)x=8;
		else if(str.find("__int128")!=T||str.find("long double")!=T)x=16;
		
		if(str.find("]")!=T)
		{
			int x=str.find("[");
			int y=str.find("]");
			string now=str.substr(x+1,y-x-1);
			y=stoll(now);
			cout<<"now "<<now<<" "<<y<<endl;
		}
		ans+=x*y;
		cout<<x<<" "<<y<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
	cout<<ceil(ans/1024)<<endl;
	cout<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	for(int i=1;i<=__;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}