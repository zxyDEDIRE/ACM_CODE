/*！*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
int p[maxn];
int n,m;
void solve()
{
	cin>>n;m=n*(n-1)/2;
	for(int i=1;i<=m;i++)
		cin>>p[i];
	sort(p+1,p+1+m);
	// for(int i=1;i<=m;i++)
	// 	cout<<p[i]<<" ";cout<<endl;
	int t=n-1;
	int s=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=p[s];
		s+=t;
		t--;
	}
	a[n]=a[n-1];
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";cout<<endl;
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
 1  2  3  4 5 6 7 8 9 10
-2 -2 -2 -2 0 0 0 0 0 3
 1  1  1  1 2 2 2 3 3 4


3 5 7 17

3 3 3
5 5
7

*/