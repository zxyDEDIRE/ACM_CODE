/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
int pre[maxn];
int p[maxn];
string str;
ll n,m,k;
bool check(int len)
{
	int pr=(1+len+1)/2;
	ll sum=0;
	for(int i=1;i<len;i++)
		sum+=1ll*(p[i+1]-p[i]-1)*min(i,len-i);
	if(sum<=k)return 1;
	cout<<sum<<endl;
	for(int i=2;i+len-1<=m;i++)
	{
		int now=(i+i+len-1+1)/2;
		sum-=pre[p[pr]]-pre[p[i-1]-1];
		if(len%2==0)sum+=pre[p[i+len-1]]-pre[p[pr]-1];
		else sum+=pre[p[i+len-1]]-pre[p[now]-1];
		if(sum<=k)return 1;
		pr=now;
	}
	return 0;
}
void solve()
{
	cin>>n>>k>>str;
	m=0;
	for(int i=1;i<=n;i++)
	{
		if(str[i-1]=='6')p[++m]=i;
		pre[i]=pre[i-1]+(str[i-1]=='9');
	}
	int l=0,r=m,ans=0;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=l,l=mid;
		else r=mid;
	}
	while(ans<m&&check(ans+1))ans++;
	cout<<ans<<endl;
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
5
10 6 9669996966   4
10 6 6669699666   5
10 6 6669969666   5
10 6 6699996669   4
10 6 6669699666   5

10 6 
9669996966
4

10 6 
6669699666
5
*/