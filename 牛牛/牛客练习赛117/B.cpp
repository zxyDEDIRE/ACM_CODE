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
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int l,r,k;
		cin>>l>>r>>k;
		if(k==0){
			cout<<((r-l+1))%2<<endl;
		}
		else if(l==r){
			if(l&1)cout<<1<<endl;
			else cout<<0<<endl;
		}
		else
		{
			if(l%2==0)l++;
			if(r&1)r++;
			cout<<((r-l+1)/2)%2<<endl;
		}
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}