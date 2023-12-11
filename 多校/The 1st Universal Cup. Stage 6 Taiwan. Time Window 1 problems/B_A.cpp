#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
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
void solve(){
    Matrix A, B;
    int n, k, d;
    scanf("%d%d%d",&n,&k,&d);

    if(((k & 1) && d <= 2) || d < 2){
        puts("0");
        return ;
    }
    
    A.Mat[0][0] = d - 2, A.Mat[0][1] = d - 1;
    A.Mat[1][0] = d - 1, A.Mat[1][1] = 0;
    B = ksm(A, k - 1);
    ll ans = B.Mat[1][0] * d % mod;
    cout<<"Anns "<<ans<<endl;

    //ans = ((w-1)^2 -(w-1)+1)^(n-1)^(k)*f(n,w);

    ll w=d;
    

    printf("%lld\n",res);
    return ;
}

void test(){
    int f[10][10];
}
int main(){
    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}