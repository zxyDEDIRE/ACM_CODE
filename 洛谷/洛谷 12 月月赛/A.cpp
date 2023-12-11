/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int a[maxn],b[maxn];
int n;
inline void read(int &x){
   int s = 0, w = 1; char ch = getchar();
   while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar(); }
   while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
   x = s*w;
   return ;
}

inline void write(__int128 x){
    if(x<0){
    	putchar('-');
		x=-x;
	}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}  
void solve()
{
	read(n);
	for(int i=1;i<=n;i++)
		read(a[i]);
	for(int i=1;i<=n;i++)
		read(b[i]);
	__int128 ans_a=0,sum_a=0;
	__int128 ans_b=0,sum_b=0;
	__int128 ma=0,lll=1;
	for(int i=1;i<=n;i++)
	{
		ans_a+=lll*n*b[i]*b[i];
		sum_a+=b[i];
	}
	for(int i=0;i<=n;i++)
	{
		sum_b-=lll*b[i];
		sum_a+=lll*a[i];
		ans_b-=lll*n*b[i]*b[i];
		ans_a+=lll*n*a[i]*a[i];
		ma=max(ma,ans_a+ans_b-(sum_a+sum_b)*(sum_a+sum_b));
	}
	write(ma);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}