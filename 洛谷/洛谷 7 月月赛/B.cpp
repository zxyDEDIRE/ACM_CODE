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
int suf[maxn];
int p[maxn];
int a[maxn];
int n,m;
struct ST{
	int f[maxn][30];
	void init()
	{
		for(int i=1;i<=n;i++){//距离为0初始化 
			f[i][0]=p[i];
			if(f[i][0]==0)f[i][0]=INF;
		}
		int t=log(n)/log(2)+1;//j定位 
		for(int j=1;j<t;j++)
		{
			for(int i=1;i<=n-(1<<j)+1;i++)
			{
				f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
				//f[i][j-1]为f[i][j]的长为2^j-1的前半段，另一段为f[i+(1<<(j-1))][j-1] 
			}
		} 
	}
	int query(int l,int r)
	{
		int k=log2(r-l+1);
		return min(f[l][k],f[r-(1<<k)+1][k]);
	}
}st;
int A()
{
	memset(suf,0,sizeof(int)*(n+2));
	int len=0,flag=1,L=0;
	int t=-1;
	p[n+1]=n+1;
	for(int r=n+1,l=n;r>=1;r--)
	{
		l=r-1;
		while(l>=1&&p[l]==0)l--;
		int len_1=r-l-1;
		int len_2=p[r]-p[l]-1;
		if(len==0&&len_1-len_2==1)len=1,r=l;
		else if(len_1==len_2)continue;
		else
		{
			L=l;
			break;
		}
	}
	for(int i=n;i>L;i--){
		if(p[i]==0)
			suf[i]=1;
		suf[i]+=suf[i+1];
	}
	int cnt=0;
	for(int i=1;i<n;i++)
	{
		if(suf[i]&&st.query(i+1,n)>=i)cnt+=suf[i],cout<<i<<" "<<suf[i]<<endl;
	}
	return cnt;
}
void solve()
{
	cin>>n>>m;
	memset(p,0,sizeof(int)*(n+1));
	
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		p[x]=y;
		a[y]=x;
	}
	st.init();
	int ans=0;
	ans+=A();
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}