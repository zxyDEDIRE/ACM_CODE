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
using B=bitset<100>;
int a[maxn];
int m,L;
int f(int x)
{
	return __builtin_popcount(x);
}
void solve()
{
	cin>>m>>L;
	for(int i=0;i<m;i++)
		cin>>a[i];
	int ans=0;
	cout<<endl;
	for(int x=0;x<=L;x++)
	{
		int flag=1;
		for(int i=0;i<m;i++)
			if(f(x+i)%2!=a[i])
				flag=0;
		ans+=flag;
		if(flag)
		{
			vector<int>v;
			int y=x;
			while(y){
				v.push_back(y%2);
				y>>=1;
			}
			for(auto i:v)
				cout<<i<<" ";cout<<endl;
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}
/*
1
3 100
0 1 0
*/