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
void solve()
{
	string str;
	int n,q,l,r;
	cin>>n>>q>>str;
	str=" "+str;
	for(int i=1;i<=n;i++)
		p[i]=1;
	while(q--)
	{
		cin>>l>>r;
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			int _sum=sum+p[i];
			if(sum>=l&&_sum<=r)
				p[i]*=2;
			else if(sum<l&&_sum>=l)
				p[i]+=(_sum-l+1);
			else if(sum<r&&_sum>r)
				p[i]+=(r-sum);
			sum=_sum;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=p[i];j++)
			cout<<str[i];
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