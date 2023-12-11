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
char ch[maxn];
int pre[maxn];
int n,q;
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>ch[i];
	for(int i=1;i<n;i++)
	{
		if(ch[i]==ch[i+1])pre[i]++;
		pre[i]+=pre[i-1];
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		if(l==r)cout<<0<<endl;
		else cout<<(pre[r-1]-pre[l-1])<<endl;
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