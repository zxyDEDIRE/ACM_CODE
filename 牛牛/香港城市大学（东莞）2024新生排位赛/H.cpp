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
ll p[maxn];
int n;
void solve()
{
	cin>>n;
	if(n&1)//ji
	{
		for(int i=1;i<n;i++)
			cout<<0<<" ",p[i]=0;
		p[n]=n;
		cout<<n<<endl;
	}
	else
	{
		p[1]=0;
		cout<<0<<" ";
		for(int i=2;i<n;i++)
			cout<<1<<" ",p[i]=1;
		p[n]=n;
		cout<<n<<endl;
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
*/