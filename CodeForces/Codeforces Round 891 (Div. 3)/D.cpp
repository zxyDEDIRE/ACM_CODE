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
int a[maxn];
int b[maxn];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	int ma=a[1]-b[1];
	for(int i=1;i<=n;i++)p[i]=a[i]-b[i],ma=max(ma,p[i]);
	vector<int>v;
	for(int i=1;i<=n;i++)
		if(p[i]==ma)
			v.push_back(i);
	cout<<v.size()<<endl;
	for(auto x:v)
		cout<<x<<" ";
	cout<<endl;

}
signed main(){
 // freopen("in.txt","r",stdin);
 // freopen("out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3 1 2 4
4 3 2 1

4-a[x]>=1-b[x]
4-1>=a[x]-b[x];

a[x]-a[y]>=b[x]-b[y]
a[x]-b[x]>=a[y]-b[y];
*/