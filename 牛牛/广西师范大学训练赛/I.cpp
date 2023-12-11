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
int pre[maxn];
int p[maxn];
int n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=2;i<=n;i++)
	{
		if(p[i]<p[i-1])pre[i]++;
		pre[i]+=pre[i-1];
	}
	int flag=1;
	for(int i=1;i+k-1<=n;i++)
	{
		int now=pre[i+k-1]-pre[i];
		if(now==0){
			flag=0;
			break;
		}
	}
	if(flag){
		sort(p+1+n-k,p+1+n);
	}
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
	cout<<endl;
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
6 6
1 2 3 4 6 5
*/