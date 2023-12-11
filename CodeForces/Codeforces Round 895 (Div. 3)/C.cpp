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
ll l,r;
void solve()
{
	cin>>l>>r;
	if(r<=2){
		cout<<-1<<endl;
		return ;
	}
	if(r-l>=1)
	{
		if(r>=4&&r%2==0)cout<<r/2<<" "<<r/2<<endl;
		else if((r-1)>=4&&(r&1))cout<<(r-1)/2<<" "<<(r-1)/2<<endl;
		else cout<<-1<<endl;
	}
	else
	{
		for(int j=2;j<=sqrt(l);j++)
			if(l%j==0){
				// cout<<j<<" "<<l/j<<endl;
				int x=j;
				int y=l/j;
				if(x==1||y==1)continue;
				cout<<x*(y-1)<<" "<<x<<endl;
				return ;
		}
		cout<<-1<<endl;
	}
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

19*3=
*/