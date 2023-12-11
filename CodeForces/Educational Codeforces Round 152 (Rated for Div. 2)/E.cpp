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
		cout<<"A"<<endl;
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
bool check_2(int l,int r,int MI,int MA)
{
	if(st.Max(l,r)>MA)return 0;
	if(st.Min(l,r)<MI)return 0;
	return 1;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	st.init();
	ll res=0;
	for(int i=1;i<=n;i++)
	{
		int l,r,ans_1,ans_2;
		l=i,r=n,ans_1=i;
		while(l<r-1)
		{
			int mid=(l+r)>>1;
			if(check_1(i,mid,p[i]))ans_1=mid,l=mid;
			else r=mid;
		}
		while(ans_1<n&&check_1(i,ans_1+1,p[i]))ans_1++;
		if(ans_1==i)continue;
		res+=ans_1-i;
		cout<<"ans_1 ";
		cout<<i<<" "<<ans_1<<endl;
		int MA=st.Max(i,ans_1);

		l=1,r=i,ans_2=i;
		while(l<r-1)
		{
			int mid=(l+r)>>1;
			if(check_2(mid,i,p[i],MA))ans_2=mid,r=mid;
			else l=mid;
		}
		while(ans_2>1&&check_2(ans_2-1,i,p[i],MA))ans_2--;
		cout<<"ans_2 ";
		cout<<ans_2<<" "<<i<<endl;
		res+=(i-ans_2)*(ans_1-i);
		cout<<i-ans_2<<" "<<ans_1-i<<" "<<(i-ans_2)*(ans_1-i)<<endl;
		cout<<endl;
	}
	cout<<res<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
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
/*
大的一定在小的后面
1 2 3 4 5 6
5 3 6 1 4 2
  1 1
1 1 1
      1 1
      1 1 1
*/