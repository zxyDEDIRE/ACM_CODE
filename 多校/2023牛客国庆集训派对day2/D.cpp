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
int in()
{
	int a,b,c;
	scanf("%d:%d:%d",&a,&b,&c);
	return a*60*60+b*60+c;
}
void solve()
{
	int a=in();
	int b=in();
	if(b>a)cout<<b-a<<endl;
	else cout<<a-b<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
		solve();
	return 0;
}