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
int a[maxn];
int n,m,k,N;
void solve()
{
	cin>>n>>m>>k;
	N=n*m;
	for(int i=1;i<=n*m;i++)
		cin>>p[i];
	sort(p+1,p+1+N);
	int fl=upper_bound(p+1,p+1+N,p[1]+k)-p;
	fl--;
	if(fl<n){
		cout<<0<<endl;
		return ;
	}
	// cout<<"fl "<<fl<<endl;
	ll ans=0;
	for(int i=1,j=1;i<=n;i++)
	{
		vector<int>now;
		// cout<<"J "<<j<<endl;
		while(j<=fl && fl-j+1 > n-i && (int)now.size()<m)
			now.push_back(p[j]),j++;
		ans+=now[0];
	}
	cout<<ans<<endl;

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
2 2 1 2 3 2 2 3

1 2 
2 2
2 3
2 3
*/