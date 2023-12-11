/*！*/
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
int s[maxn];
int t[maxn];
int n,m,top,len;
ll b,p;
void solve()
{
	cin>>n>>m>>b>>p;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	cout<<endl;
	top=1;
	while(m--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x,w;
			cin>>x>>w;
			s[x]=w;
			top=min(top,x);
		}
		else
		{
			int len;
			cin>>len;
			for(int i=1;i<=len;i++)
				cin>>t[i];
		}

	}
}
signed main(){
 // freopen("in.txt","r",stdin);
 // freopen("out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}