#include<bits/stdc++.h>
#define int long long
#define ll long long 
#define ull unsigned long long 
#define ldb long double
#define LS p<<1
#define RS p<<1|1
#define loop(ii,xx,yy) for(auto ii=xx;ii<=yy;ii++)
#define doop(ii,xx,yy) for(auto ii=xx;ii>=yy;ii--)
using namespace std;
ll read(){ll x=0,y=1;char ch=getchar();while((ch<'0'||ch>'9')&&ch!=EOF){if(ch=='-') y=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+(ch^48);	ch=getchar();}return x*y;}
const int Mod=998244353;
const int INF=0x3f3f3f3f;
const long long N=1e6+5;
const long long M=1e5+5;
ll n,m;
int randint(int x,int y){return rand()%(y-x+1)+x;}
int fa[N];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	while(1){
		system("make.exe > a.in");
		system("C.exe < a.in > sb.out");
		system("C_1.exe < a.in > nb.out");
		if(system("fc nb.out sb.out")){
			break;
		}
	}
	return 0;
}