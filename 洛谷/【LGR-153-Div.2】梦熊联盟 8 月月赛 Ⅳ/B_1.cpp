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
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		p[i]=i;
		// cin>>p[i];
	int ans=INF;
	do{
		int ma=0,mi=INF;
		for(int i=1;i<=n;i++)
		{
			ma=max(ma,p[i]+p[i%n+1]);
			mi=min(mi,p[i]+p[i%n+1]);
		}
		if(ma-mi<=ans){
			ans=min(ans,ma-mi);
			cout<<ans<<"   ";
			for(int i=1;i<=n;i++)
				cout<<p[i]<<" ";cout<<endl;
		}
	}while(next_permutation(p+1,p+1+n));
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
1 7 3 5 4 6 2 8
1 3 4 2
 7 5 6 8

1 9 3 7 5 6 4 8 2 10
1 3 5 4 2
 9 7 6 8 10

*/