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
	ll mi=INF,fl=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]<mi)
		{
			mi=p[i];
			fl=i;
		}
	}
	// sort(p+1,p+1+fl);
	for(int i=fl;i<n;i++)
		if(p[i+1]<p[i]){
			cout<<"-1\n";
			return ;
		}
	cout<<fl-1<<endl;
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
5
6 4 1 2 5
4 1 2 5 6
1 2 4 5 6
*/