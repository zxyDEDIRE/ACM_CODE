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
int f[maxn][31];
int h[maxn][31];
int sum[maxn];
int p[maxn];
int n;
struct ST{
	void init()
	{
		for(int i=1;i<=n;i++)//距离为0初始化 
			f[i][0]=p[i],h[i][0]=p[i];
		int t=log(n)/log(2)+1;//j定位 
		for(int j=1;j<t;j++)
		{
			for(int i=1;i<=n-(1<<j)+1;i++)
			{
				f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
				h[i][j]=min(h[i][j-1],h[i+(1<<(j-1))][j-1]);
				//f[i][j-1]为f[i][j]的长为2^j-1的前半段，另一段为f[i+(1<<(j-1))][j-1] 
			}
		} 
	}
	int Max(int l,int r)
	{
		int k=log2(r-l+1);
		return max(f[l][k],f[r-(1<<k)+1][k]);
	}
	int Min(int l,int r)
	{
		int k=log2(r-l+1);
		return min(h[l][k],h[r-(1<<k)+1][k]);
	}
}st;
bool check_1(int l,int r,int w)
{
	return st.Min(l,r)>=w;
}
bool check_2(int l,int r,int w)
{
	return st.Max(l,r)>w;
}
bool check_3(int l,int r,int w)
{
	if(st.Min(l,r)<w)return 0;
	return 1;
}
int R[maxn];//最小值覆盖左域
int L[maxn];//最左次大值
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	st.init();
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n,ans=i;
		while(l<r-1)
		{
			int mid=(l+r)>>1;
			if(check_1(i,mid,p[i]))ans=mid,l=mid;
			else r=mid;
		}
		while(ans<n&&check_1(i,ans+1,p[i]))ans++;
		R[i]=ans;
		cout<<"R "<<i<<" "<<ans<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n,ans=n+1;
		while(l<r-1)
		{
			int mid=(l+r)>>1;
			if(check_2(i,mid,p[i]))ans=mid,r=mid;
			else l=mid;
		}
		while(ans>i&&check_2(i,ans-1,p[i]))ans--;
		L[i]=ans;
		cout<<"L "<<i<<" "<<ans<<endl;
		sum[i]=sum[i-1]+ans;
	}
	cout<<"SUM \n";
	for(int i=1;i<=n;i++)
		cout<<sum[i]<<" ";cout<<endl;
	ll res=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,ans=i;
		while(l<r-1)
		{
			int mid=(l+r)>>1;
			if(check_3(mid,i,p[i]))ans=mid,r=mid;
			else l=mid;
		}
		while(ans>1&&check_3(ans-1,i,p[i]))ans--;
		res+=R[i]*(i-ans+1)-(sum[i]-sum[ans-1])+L[i];
		cout<<"i "<<i<<" "<<R[i]<<" "<<ans<<" "<<i-ans+1<<endl;
		cout<<"sum "<<sum[i]-sum[ans-1]<<endl;
		cout<<R[i]*(i-ans+1)-(sum[i]-sum[ans-1])+L[i]<<endl;
		cout<<endl;
	}
	cout<<res<<endl;
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
10
5 1 6 2 8 3 4 10 9 7
  
*/