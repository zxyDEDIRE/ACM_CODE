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
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int f[maxn][30];
int p[maxn];
int a[maxn];
int b[maxn];
int n,l,r;
void st()
{
	for(int i=1;i<=n;i++)
		f[i][0]=b[i];
	int t=log(n)/log(2)+1;//j定位 
	for(int j=1;j<t;j++)
		for(int i=1;i<=n-(1<<j)+1;i++)
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
int query(int l,int r)
{
	int k=log2(r-l+1);
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
void solve()
{
	int sum=0;
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++)
		cin>>p[i],sum+=p[i];
	for(int i=1;i<=n;i++)
		a[i]=a[i-1]+p[i]-l;
	for(int i=n;i>=1;i--)
		b[i]=b[i+1]+p[i]-r;
	st();
	int ma=0;
	for(int i=1;i<=n;i++)
	{
		int x=a[i-1]+query(i,n);
		ma=max({ma,a[i],b[i],x});
	}
	cout<<sum-ma<<endl;

}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}