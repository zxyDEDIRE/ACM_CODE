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
const int maxn=2e5+100;
int p[2][maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[0][i];
	p[0][0]=p[1][0]=INF;
	int cnt[2];
	cnt[0]=n;
	int fl=0;
	int ans=0;
	while(cnt[fl]>1)
	{
		ans++;
		cnt[fl^1]=0;
		for(int i=1;i<=cnt[fl];i++)
		{
			if(i==cnt[fl]&&p[fl][i]<p[fl^1][cnt[fl^1]]);
			else if(i<cnt[fl]&&p[fl][i]<p[fl][i+1]&&p[fl][i]<p[fl^1][cnt[fl^1]]);
			else p[fl^1][++cnt[fl^1]]=p[fl][i];
		}
		fl^=1;
		// cout<<cnt[fl]<<endl;
		// for(int i=1;i<=cnt[fl];i++)
		// 	cout<<p[fl][i]<<" ";cout<<endl;
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