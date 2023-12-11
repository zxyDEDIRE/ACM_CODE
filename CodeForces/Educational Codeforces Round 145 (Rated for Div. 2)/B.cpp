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
const int INF=1e9+7;
const int maxn=1e6+100;
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
	int n;
	// cin>>n;
	read(n);
	int l=0,r=n,ans=r;

	auto check=[&](int mid)->bool{
		int m,ans;
		if(mid&1)
		{
			m=(mid+1)/2;
			ans=(2+2*m)*m*2-4*m;
		}
		else
		{
			m=mid/2+1;
			ans=(1+2*m-1)*m*2-m*4+1;
		}
		return ans>=n;
	};
	while(l<r-1)
	{
		int mid=(l+r)/2;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	while(ans>0&&check(ans-1))ans--;
	write(ans);
	puts("");

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;read(__);
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
0 1 2
1 5
*/