/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int fp(int b,int p)
{
	if(p==0)return 1ll;
	int r=1;
	while(p){
		if(p&1)r=(r*b)%mod;
		p>>=1;
		b=(b*b)%mod;
	}
	return r;
}
int mull(int a,int b)
{
	if(a==0||b==0)return 0;
	int qw=0;
	while(b)
	{
		if(b&1)qw=(qw+a)%mod;
		a=(a+a)%mod;
		b>>=1;
	}
	return qw;
}
int C(int n,int m)
{
    if(n<m) return 0;
    int res=1;
    for(int i=1;i<=m;i++)
    {
        res*=((n-m+i)%mod)*fp(i,mod-2)%mod;
        res%=mod;
    }
    return res;
}
void solve()
{
	int n,r1,r2,r,a,h;
	cin>>n>>r1>>r2>>r>>a>>h;
	int se=r2*r2;
	int fi=min(se,(r1+r)*(r1+r));
	int t=fi*fp(se,mod-2)%mod;
	int tt=(se-fi)*fp(se,mod-2)%mod;
	int ans=0;
	for(int i=((h+a-1)/a);i<=n;i++)
	{
		ans=ans+mull(C(n,i),mull(fp(t,i),fp(tt,n-i)));
		ans%=mod;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
怎么求C(n,m)+C(n,m+1)+...+C(n,n)
1<=n<=5e6
*/