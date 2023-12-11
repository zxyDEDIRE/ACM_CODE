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
const int M = 998244353;
int ff[maxn+5];  //打表，记录n!，避免重复计算
 
//求最大公因数
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
 
//解线性同余方程，扩展欧几里德定理
int x,y;
void Extended_gcd(int a,int b)
{
    if(b==0)
    {
        x=1;
        y=0;
    }
    else
    {
        Extended_gcd(b,a%b);
        long t=x;
        x=y;
        y=t-(a/b)*y;
    }
}
 
//计算不大的C(n,m)
int C(int a,int b)
{
    if(b>a)
        return 0;
    b=(ff[a-b]*ff[b])%M;
    a=ff[a];
    int c=gcd(a,b);
    a/=c;
    b/=c;
    Extended_gcd(b,M);
    x=(x+M)%M;
    x=(x*a)%M;
    return x;
}
 
//Lucas定理
int Combination(int n, int m)
{
    int ans=1;
    int a,b;
    while(m||n)
    {
        a=n%M;
        b=m%M;
        n/=M;
        m/=M;
        ans=(ans*C(a,b))%M;
    }
    return ans;
}
bool vis[maxn];
int t[maxn];
int p[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	int mm=m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		vis[p[i]]=1;
	}
	int now=0;
	while(1){
		if(vis[now])now++;
		else if(m)m--,now++;
		else break;
		t[m]++;
	}
	for(int i=mm;i>=0;i--)
		t[i]+=t[i+1];
	int ans=0;
	for(int i=0;i<=mm;i++)
	{
		int x=t[i]+i-1;
		int y=i;
		ans+=Combination(x,y)%mod;
		ans%=mod;
	}
	cout<<ans<<endl; 
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	ff[0]=1;
    for(int i=1; i<=maxn-100; i++) //预计算n!
        ff[i]=(ff[i-1]*i)%M;
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3 2
0 1 3

0 0 0 1 3
0 0 1 1 3
0 1 1 1 3

0 0 1 2 3
0 1 1 2 3
0 1 2 2 3
0 1 2 3 3

0 1 2 3 4

2 10->9
3 10->36
1 1 8


f(2,10)=9;
f(2,9)=9
f(3,10)=f(2,9)+f(2,8)+f(2,7)+f()
*/