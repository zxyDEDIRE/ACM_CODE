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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int p[maxn];
int n;
struct ST{
	int f[maxn][30];
	int h[maxn][30];
	void init()
	{
		for(int i=1;i<=n;i++)//距离为0初始化 
			f[i][0]=h[i][0]=p[i];
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
	int MA(int l,int r)
	{
		int k=log2(r-l+1);
		return max(f[l][k],f[r-(1<<k)+1][k]);
	}
	int MI(int l,int r)
	{
		int k=log2(r-l+1);
		return min(h[l][k],h[r-(1<<k)+1][k]);
	}
}st;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	st.init();
	int ans=1;
	for(int i=1,r=1;i<=n;i++)
	{
		while(1)
		{
			if(r==n)break;
			int ma=st.MA(i,r+1);
			int mi=st.MI(i,r+1);
			if(ma-mi<=1)r++;
			else break;
		}
		ans=max(ans,r-i+1);
	}
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