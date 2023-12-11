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
int f[maxn];
int a[maxn];
int n,m,k;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void un(int x,int y)
{
	int fa=find(x);
	int fb=find(y);
	if(fa!=fb)
		f[fa]=fb;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		un(x,y);
	}
	cin>>k;
	for(int i=1;i<=k;i++)
		cin>>a[i];
	for(int i=2;i<=k;i++)
	{
		int fa=find(a[1]);
		int fb=find(a[i]);
		if(fa!=fb){
			cout<<"NO"<<endl;
			return ;
		}
	}
	cout<<"YES"<<endl;
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