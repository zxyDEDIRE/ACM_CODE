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
int p[maxn],pre[maxn];

int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i],pre[i]=(pre[i-1]+p[i])%1000;
	if(n>=1000)
	{
		map<int,int>mp;
		for(int i=1;i<=n;i++)
		{
			if(!mp.count(pre[i]))
				mp[pre[i]]=i;
			else
			{
				int l=mp[pre[i]]+1;
				int r=i;
				cout<<0<<endl;
				cout<<r-l+1<<" ";
				for(int i=l;i<=i;i++)
					cout<<i<<" ";
				cout<<endl;
				return ;
			}
		}
	}
	else
	{

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