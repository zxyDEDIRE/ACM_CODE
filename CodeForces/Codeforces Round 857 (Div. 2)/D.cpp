/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
pii p[maxn];
int mx_b[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	sort(p+1,p+1+n);
	mx_b[n+1]=0;
	for(int i=n;i>=1;i--)
		mx_b[i]=max(mx_b[i+1],p[i].second);
	set<int>s;
	int ans=INF;
	for(int i=1;i<=n;i++)
	{
		int ma=INF;
		auto it=s.lower_bound(p[i].first);
		if(it!=s.end())
		{
			if(*it>=mx_b[i+1])	
				ma=min(ma,abs(p[i].first-*it));
		}
		if(it!=s.begin())
		{
			it--;
			if(*it<=mx_b[i+1])	
				ma=min(ma,abs(p[i].first-*it));
		}
		if(i!=n)
			ma=min(ma,abs(p[i].first-mx_b[i+1]));
		ans=min(ans,ma);
		s.insert(p[i].second);
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}