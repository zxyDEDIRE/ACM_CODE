// #include<bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// #define pp(x) array<int,x>
// using ull=unsigned long long;
// using ll=long long;
// using pii=pair<int,int>;
// using pdd=pair<double,double>;
// const int dx[]={0,0,1,-1,1,-1,1,-1};
// const int dy[]={1,-1,0,0,1,-1,-1,1};
// const int mod=998244353;
// const int inf=0x3f3f3f3f;
// const int INF=1e9+7;
// const int maxn=1e2+100;
// int dp[maxn][maxn][3];
// int n,k;
// int solve(int n,int k)
// {
//     // cin>>n>>k;
//     for(int i=0;i<=n;i++)
//         for(int j=0;j<=k;j++)
//             dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=0;
//     dp[0][0][0]=1;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=0;j<i;j++)
//         {
//             if(dp[i-1][j][0]!=-1)
//                 dp[i][j][0]+=dp[i-1][j][0],dp[i][j+1][1]+=dp[i-1][j][0],dp[i][j+1][2]+=dp[i-1][j][0];
//             if(dp[i-1][j][1]!=-1)
//                 dp[i][j][0]+=dp[i-1][j][1],dp[i][j+1][2]+=dp[i-1][j][1];
//             if(dp[i-1][j][2]!=-1)
//                 dp[i][j][0]+=dp[i-1][j][2],dp[i][j+1][1]+=dp[i-1][j][2];
//         }
//     }
//     ll ans=dp[n][k][0]+dp[n][k][1]+dp[n][k][2];
//     // cout<<dp[n][k][0]<<" "<<dp[n][k][1]<<" "<<dp[n][k][2]<<endl;
//     // cout<<ans<<endl;
//     return ans;
// }
// signed main(){
//  // freopen("data.in","r",stdin);
//  // freopen("data.out","w",stdout);
//     // ios::sync_with_stdio(false);
//     // cin.tie(nullptr);cout.tie(nullptr);
//     // int __;cin>>__;
//     // while(__--)
//         // solve();
//     for(int i=1;i<=10;i++)
//     {
//         for(int j=1;j<=10;j++)
//             printf("[%2d,%2d]:%5d  ",i,j,solve(i,j));
//             // cout<<"["<<i<<","<<j<<"]:"<<solve(i,j)<<" ";
//         // cout<<endl;
//         printf("\n");
//     }
//     return 0;
// }
// /*

// 1: 2*n^1
// 2: 2*(n-1)^2
// 3: (4*n^3+2*n)/3
// 4:


// dp[1][i]=2;
// dp[i][j]=dp[i][j-1]+dp[i-1][j]+dp[i-1][j-1];

// 2  2  2   2
// 4  8  12  16
// 6  18 38  66
// 8  32 88  192
// 10 50 170 450

// 2  2  2  2
// 4   
// 6
// 8

// */
#include<bits/stdc++.h>
using namespace std;
long long ksm(long long a,long long b,long long mod){
    long long res=1;
    a%=mod;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
const int N=1e6+10,mod=998244353;
long long fac[N],inv[N];
void init(int n=N-10){
    fac[0]=1;
    for(int i=1;i<=n;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    inv[n]=ksm(fac[n],mod-2,mod);
    for(int i=n-1;i>=0;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
long long C(int n,int m){
    if(n<0||m<0||n<m) return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
void solve(){
    int n,k;
    cin>>n>>k;
    if(k>n){
        cout<<0<<'\n';
        return;
    }
    if(k==0){
        cout<<1<<'\n';return;
    }
    int ci=n-k+1;
    long long ans=0;
    for(int i=0;i<=k;i++){
        ans=(ans+C(i+ci-1,i)*C(ci,k-i)%mod)%mod;
    }
    cout<<ans<<'\n';
}
/*
1

*/
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
