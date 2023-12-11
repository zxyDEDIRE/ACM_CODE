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
string w[]={"Monday","Tuesday","Wednesday","Thursday","Friday"};
int f(pp(3) x)
{
	int ans=x[0]*12*30+30*x[1]+x[2];
	return ans;
}
void solve()
{
	pp(3) a,b;
	string str;
	cin>>a[0]>>a[1]>>a[2]>>str;
	cin>>b[0]>>b[1]>>b[2];
	int x=f(a)%5;
	int y=f(b)%5;
	int now=0;
	for(int i=0;i<5;i++)
		if(w[i]==str)now=i;
	now=now+(y-x);
	now=(now%5+5)%5;
	cout<<w[now]<<endl;
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