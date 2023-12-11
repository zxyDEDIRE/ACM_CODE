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
int pre[maxn][2];
char s[maxn];
int n;
void solve()
{
	cin>>s+1;
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		int fa=0,fb=0;
		int x=s[i]-'0';
		if((x%2)!=(i%2))fa=1;
		if((x%2)==(i%2))fb=1;
		pre[i][0]=pre[i-1][0]+fa;
		pre[i][1]=pre[i-1][1]+fb;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			ans+=min(pre[j][0]-pre[i-1][0],pre[j][1]-pre[i-1][1]);
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
10001
10101
*/