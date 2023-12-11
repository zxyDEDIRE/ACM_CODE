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
char s[maxn];
int n;
void solve()
{
	cin>>n;
	vector<int>v;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]=='1')
		{
			cnt++;
		}
		else
		{
			if(cnt)v.push_back(cnt);
			cnt=0;
		}
	}
	if(cnt)v.push_back(cnt);
	sort(v.begin(),v.end(),[&](int a,int b){return a>b;});
	int ans=0;
	if(v.size())ans=max(ans,v[0]);
	if(v.size()>=2)ans=max(ans,v[0]+v[1]);
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