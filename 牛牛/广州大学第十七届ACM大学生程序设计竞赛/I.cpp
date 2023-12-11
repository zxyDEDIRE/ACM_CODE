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
int a[maxn];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		p[i]=(1ll<<p[i]);
	}
	sort(p+1,p+1+n,[&](int a,int b){
		return a>b;
	});
	int ma=0,mi=0;
	int l=0,r=0;
	for(int i=1;i<=n;i++)
	{
		l=ceil(1.0*r/p[i])*p[i];
		r=l+p[i];
		mi=max(mi,r);
	}
	l=1,r=n;
	for(int i=1;i<=n;i+=2)
		a[i]=p[r--];
	for(int i=2;i<=n;i+=2)
		a[i]=p[l++];

	l=0,r=0;
	for(int i=1;i<=n;i++)
	{
		l=ceil(1.0*r/a[i])*a[i];
		r=l+a[i];
		ma=max(ma,r);
	}
	cout<<mi<<" "<<ma<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*

*/