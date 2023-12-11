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
const int maxn=2e6+100;
int f[maxn][23];
bool vis[maxn];
int p[maxn];
int n,m;
inline void read(int &x){
   int s = 0, w = 1; char ch = getchar();
   while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar(); }
   while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
   x = s*w;
   return ;
}
inline int find(int r,int t){
	return f[r][t]=(f[r][t]==r)?f[r][t]:find(f[r][t],t);
}
inline void un(int a,int b,int t)
{
	int fa=find(a,t);
	int fb=find(b,t);
	f[fa][t]=fb;
}
inline void merge(int l,int r)
{
	int L=n+(n-r+1);
	// cout<<"l "<<l<<" r "<<r<<endl;
	// cout<<"L "<<L;
	for(int i=21;i>=0;i--)
	{
		int t=(1<<i);
		if(r-l+1>=t*2&&l<r)
		{
			un(l,L,i);
			l+=t;
			L+=t;
		}
	}
	// cout<<" R "<<L<<endl;
	// cout<<endl;
}
inline void solve()
{
	read(n);
	for(int i=1;i<=n*2;i++)
		for(int j=0;j<=21;j++)
			f[i][j]=i;
	for(int i=1;i<=(n*2+2);i++)
		read(p[i]);
	for(int i=3;i<=(n*2+2);i++)
	{
		int l,r;
		l=i-p[i]+1;
		(l%2==0)?l++:l;
		r=i+p[i]-1;
		(r%2==0)?r--:r;
		l=(l-1)>>1;
		r=(r-1)>>1;
		if(l>r)continue;
		merge(l,r);
	}

	for(int t=21;t>=1;t--)
	{
		int len=(1<<(t-1));
		for(int i=1;i<=n;i++)
		{
			if(f[i][t]==i)continue;
			int l=i;
			int r=find(i,t);
			un(l,r,t-1);
			un(l+len,r+len,t-1);
		}
	}
	for(int i=1;i<=n;i++)
		un(i,n*2-i+1,0);
	for(int i=2;i<=n;i++)
	{
		int fa=find(i-1,0);
		int fb=find(i,0);
		if(fa!=fb)vis[i]=(vis[i-1]^1);
		else vis[i]=vis[i-1];
	}
	for(int i=1;i<=n;i++)
		vis[i]?putchar('b'):putchar('a');
	
}
int main(){
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}
/*
1 1 2 1 4 1 2 3 4 3 2 1
& / a / b / a / a / a /
    1   2   3   4   5
&|a|b|b|a|
4
1 1 2 1 2 5 2 1 2 1



5
1 1 2 1 4 1 2 3 4 3 2 1

*/