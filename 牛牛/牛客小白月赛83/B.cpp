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
int n,m,x;
void solve()
{
	cin>>n>>m>>x;
	vector<int>a(n,0),b(m,0);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int j=0;j<m;j++)
		cin>>b[j];
	sort(a.begin(),a.end(),[&](int a,int b){return a>b;});
	sort(b.begin(),b.end(),[&](int a,int b){return a>b;});
	while(a.size()&&a.back()==1)a.pop_back();
	while(b.size()&&b.back()==0)b.pop_back();
	int ans=0;
	int sum=0;
	for(int i=0;i<b.size();i++)
	{
		ans++;
		sum+=b[i];
		if(sum+b[i]>=x){
			break;
		}
		if(i<a.size())
		{
			sum-=b[i];
			sum+=a[i]*b[i];
			ans++;
		}
		// cout<<ans<<" "<<sum<<endl;
		if(sum>=x)break;
	}
	if(sum<x)cout<<-1<<endl;
	else cout<<ans<<endl;
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
3 2 1 
2 2 1
1 1 1
1
1 
*/