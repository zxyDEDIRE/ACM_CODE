#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define int long long
const int mod = 1e9 + 7;
const int SIZ = 3;
ll ksm(ll a, ll b){
    a %= mod;
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

struct Matrix{
    ll Mat[SIZ][SIZ];
    Matrix(){
        for(int i = 0; i < 2; i ++)
            for(int j = 0; j < 2; j ++) Mat[i][j] = 0;
    }
    inline void build(){
        for(int i = 0; i < 2; i ++){
            Mat[i][i] = 1;
        }
    }
};

Matrix operator * (const Matrix &A, const Matrix &B){
    Matrix a;
    for(int i = 0; i < 2; i ++){
        for(int j = 0; j < 2; j ++){
            for(int k = 0; k < 2; k ++){
                a.Mat[i][j] += A.Mat[i][k] * B.Mat[k][j] % mod;
                a.Mat[i][j] %= mod;
                // printf("a[%d][%d] = %lld\n",i,j,a.Mat[i][j]);
            }
        }
    }
    return a;
}

Matrix ksm(Matrix a, ll b){
    Matrix ans;
    ans.build();
    while(b){
        if(b & 1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}
int fp(int b,int p)
{
    int r=1;b%=mod;
    while(p){
        if(p&1)r=(r*b)%mod;
        p>>=1;
        b=(b*b)%mod;
    }
    return r;
}
int mull(int a,int b)
{
    int qw=0;
    while(b)
    {
        if(b&1)qw=(qw+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return qw;
}

void solve(){
    Matrix A, B;
    int n, k, d;
    cin>>n>>k>>d;

    if(((k & 1) && d <= 2) || d < 2){
        puts("0");
        return ;
    }
    B.Mat[0][0] = 0, B.Mat[0][1] = d;
    A.Mat[0][0] = d - 2, A.Mat[0][1] = 1;
    A.Mat[1][0] = d - 1, A.Mat[1][1] = 0;
    Matrix res = B * ksm(A, k - 1);

    ll ans = res.Mat[0][0] % mod;
    // cout<<ans<<endl;
    // printf("res00 = %lld\n",res.Mat[0][0]);
        
    ll w=d;

    ll SO =mull(fp(fp((mull(w-1,w-1)-(w-1)+1)%mod,n-1),k),ans)%mod;


    // ans = ans * ksm(2 * d - 3, 1ll * (n - 1) * k) % mod;
    // printf("res = %lld\n",ksm(2 * d - 3, 1ll * (n - 1) * k));
    // printf("%lld\n",SO);
    cout<<SO<<endl;
    return ;
}

signed main(){
    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}
