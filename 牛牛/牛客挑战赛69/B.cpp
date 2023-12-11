#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10,M=2e3+10;
const int mod=1e9+7;

typedef pair<int,int> pii;
typedef pair<int,long long> pil;
typedef pair<long long,int> pli;
typedef pair<long long,long long> pll;
typedef pair<string,int> psi;
typedef pair<string,string> pss;
typedef pair<int,pii> piii;
typedef pair<long long,pii>plii;


#define fi first
#define se second 
#define IOS  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

long long ksm(long long a,long long b){ long long res=1;while(b){if(b&1)res=res*a;a=a*a;b>>=1;} return res; }
long long ksm(long long a,long long b,int mod){ long long res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;} return res; }
long long gcd(long long a,long long b) {return b?gcd(b,a%b):a;};
void ps(string s){cout<<s<<'\n';}
long long exgcd(int a,int b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    long long d,x1,y1;
    d=exgcd(b,a%b,x1,y1);
    x=x1,y=x1-a/b*y1;
    return d;
}

void AC()
{
//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                   佛祖保佑, 永无bug;
}


//建图


/*
//基础并查集 
int f[N],si[N];
void init(int n){ for(int i=1;i<=n;i++) f[i]=i,si[i]=1; }
int find(int x){return f[x]=(x==f[x])?x:find(f[x]);} 
*/

/*
//基础质数筛
int q[N],cnt;
bool vis[N];
void init(int n=3e5){ vis[1]=true;   for(int i=2;i<=n;i++) { if(!vis[i]) q[cnt++]=i; for(int j=0;1ll*i*q[j]<=n;j++) { int num=q[j]*i;vis[num]=true;if(i%q[j]==0) {break;} } } } 
*/

/*
//组合数
long long fac[N],inv[N];
void init(int n){   fac[0]=inv[0]=1;    for(int i=1;i<=n;i++){      fac[i]=fac[i-1]*i%mod;      inv[i]=inv[i-1]*ksm(i,mod-2,mod)%mod;   }} 
long long C(int n,int m){   return fac[n]*inv[m]%mod*inv[n-m]%mod;}
long long P(int n,int m) { return fac[n]*inv[n-m]%mod;}
*/


int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m,k;
double x[N],y[N];
double db(double x)
{
    return x*x;
}
double get(double x1,double y1,double x2,double y2)
{
    return sqrt(db(x1-x2)+db(y1-y2));
}
double check1(double xx,double yy)
{
    double r=min(xx,n-xx);
    r=min(r,min(yy,m-yy));
   for(int i=1;i<=k;i++)
   {
       r=min(r,get(x[i],y[i],xx,yy));
   }
    return r;
}
double check(double xx)
{
    double l=0,r=m;
    double ansl=0,ansr=0;
    while(r-l>1e-9)
    {
        double ml=l+(r-l)/3.0; 
        double mr=r-(r-l)/3.0;
        ansl=check1(xx,ml),ansr=check1(xx,mr);
        if(ansl<=ansr)
        {
            l=ml;
        }
        else{
            r=mr;
        }
    }
    return max(ansl,ansr);
}
void solve()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%lf%lf",&x[i],&y[i]);
    }
    double l=0,r=n;
    double ansl=0,ansr=0;
    while(r-l>1e-9)
    {
        double ml=l+(r-l)/3.0; 
        double mr=r-(r-l)/3.0;
        ansl=check(ml),ansr=check(mr);
        if(ansl<=ansr)
        {
            l=ml;
        }
        else{
            r=mr;
        }
    }
    printf("%.10lf",max(ansl,ansr));
}

/*

*/
int main()
{
    int t=1; 
    while(t--) solve();
    return 0;
}
/*
10 10 2
5 7
5 4
*/
