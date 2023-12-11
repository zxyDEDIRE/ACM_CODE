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
bitset<maxn>vis;
int f[maxn];
int p[maxn];
int q[maxn];
int n,m,cnt;
void solve()
{
	cin>>n>>m;
	int a=0,b=0;
	cnt=0;
	vis.reset();
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(x>0)f[++cnt]=x,vis[x]=1;
		else if(x==-1)a++;
		else if(x==-2)b++;
	}
	sort(f+1,f+1+cnt);
	cnt=unique(f+1,f+1+cnt)-f-1;
	p[0]=q[m+1]=0;
	for(int i=1;i<=m;i++)
		p[i]=p[i-1]+(vis[i]==1?0:1);
	for(int i=m;i>=1;i--)
		q[i]=q[i+1]+(vis[i]==1?0:1);
	int ans=max({cnt,a,b});
	ans=min(ans,m);
	for(int i=1;i<=cnt;i++)
	{
		// int x=(i-1)+min(p[f[i]-1],a);
		// int y=(cnt-i)+min(q[f[i]+1],b);
		int l=min(f[i]-1,i-1+a);
		int r=min(m-f[i],cnt-i+b);
		ans=max(ans,x+y+1);
	}
	ans=max(ans,min(m,b+cnt));
	ans=max(ans,min(m,a+cnt));
	ans=min(ans,m);
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
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
6 7
5 -1 -2 -2 -2 -2

-2 -2 -2 -2 5

4 4 
1 1 1 1 
*/