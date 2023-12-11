/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int __int128
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e20+7;
const int maxn=1e6+100;
const int N=1e5+100;
int dp[4];
int p[maxn];
int n,a,b,c;
inline void read(int &x){
   int s = 0, w = 1; char ch = getchar();
   while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar(); }
   while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
   x = s*w;
   return ;
}

inline void write(int x){
    if(x<0){
    	putchar('-');
		x=-x;
	}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}  
void solve()
{
	// cin>>n>>a>>b>>c;
	read(n);
	read(a);
	read(b);
	read(c);
	dp[0]=dp[1]=dp[2]=-INF;
	for(int i=1;i<=n;i++)
	{
		read(p[i]);
		// cin>>p[i];/
		dp[0]=max(dp[0],p[i]*a);
		dp[1]=max(dp[1],dp[0]+p[i]*b);
		dp[2]=max(dp[2],dp[1]+p[i]*c);
	}
	write(dp[2]);
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
-1 -2 -5
1 2 -3

*/