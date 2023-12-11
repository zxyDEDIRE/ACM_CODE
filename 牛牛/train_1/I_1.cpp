/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
int pre[maxn];
int p[maxn];
string str;
int n,m,k;
bool check(int len)
{
	int pre=(1+len+1)/2;
	int sum=0;
	int a=0,b=0;
	for(int i=1;i<pre;i++)
	{
		a+=p[i+1]-p[i]-1;
		sum+=(p[i+1]-p[i]-1)*i;
	}
	for(int i=pre;i<len;i++)
	{
		b+=p[i+1]-p[i]-1;
		sum+=(p[i+1]-p[i]-1)*(len-i);
	}
	if(sum<=k)return 1;
	// cout<<sum<<endl;
	// cout<<a<<" "<<b<<endl;
	for(int i=2;i+len-1<=m;i++)
	{
		int now=(i+i+len-1+1)/2;

		sum-=a;
		// cout<<"-a "<<a<<endl;
		a-=p[i]-p[i-1]-1;
		int yu=p[now]-p[pre]-1;
		if(len%2==0)sum+=b;
		else sum+=(b-yu);
		a+=yu;
		b-=yu;
		b+=p[i+len-1]-p[i+len-2]-1;
		sum+=p[i+len-1]-p[i+len-2]-1;

		if(sum<=k)return 1;
		pre=now;
	}
	return 0;
}
void solve()
{
	cin>>n>>k>>str;
	for(int i=1;i<=n;i++)
		if(str[i-1]=='6')
			p[++m]=i;
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
10 6 
9669996966

8 6
69996966
*/