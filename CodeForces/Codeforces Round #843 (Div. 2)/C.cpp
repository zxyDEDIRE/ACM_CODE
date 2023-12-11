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
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int T=5e18;
int n,x;
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
	// cin>>n>>x;
	read(n);
	read(x);
	bitset<70>a;
	bitset<70>b(x);
	int l=n;
	for(int i=62;i>=0;i--)
	{
		a[i]=(n&(1ll<<i));
		if(a[i]==b[i]&&a[i]==0)continue;
		if(a[i]==b[i]&&a[i]==1)
		{
			int s=(1ll<<i);
			int fi=n/s*s;
			if(l<fi){cout<<-1<<endl;return ;}
		}

		if(a[i]==0){cout<<-1<<endl;return ;}
		else if(a[i]==1)
		{
			int s=(1ll<<i);
			int fi=n/s*s;
			int cnt=n-fi+1;
			int tot=(1ll<<i)-cnt+1;
			n+=tot;
		}
	}
	write(n);putchar('\n');
	// cout<<n<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
1010
1011
1100
1101
1110
1111
*/