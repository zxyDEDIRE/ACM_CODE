#include <bits/stdc++.h>
using namespace std;

#define ll long long

namespace Poly{
    const int N=3e6+10;
    const int mod=998244353;
    const int g=3,gi=332748118;//根据模数不同改变原根
    using poly=vector<long long>;
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
    int r[N];
    int limit,L;
    void init(int n,int m){
        limit=1;L=0;
        while(limit<=n+m) limit<<=1,L++;
        for(int i=0;i<limit;i++){
            r[i]=(r[i>>1]>>1)|((i&1)<<(L-1));
        }
    }
    void ntt(poly &v,int type){
        int len=v.size();
        for(int i=0;i<len;i++){
            if(i<r[i]) swap(v[i],v[r[i]]);
        }
        for(int mid=1;mid<len;mid<<=1){
            long long wn=ksm(type==1?g:gi,(mod-1)/(mid<<1),mod);
            for(int j=0,R=mid<<1;j<limit;j+=R){
                long long w=1;
                for(int k=0;k<mid;k++,w=(w*wn)%mod){
                    long long x=v[j+k],y=v[j+mid+k]*w%mod;
                    v[j+k]=(x+y)%mod;
                    v[j+k+mid]=(x-y+mod)%mod;
                }
            }
        }
        if(type==-1){
            long long inv=ksm(len,mod-2,mod);
            for(int i=0;i<len;i++){
                v[i]=v[i]*inv%mod;
            }
        }
    }
    //反转多项式系数
    void Reverse(poly &a){
        reverse(a.begin(),a.end());
    }
    //多项式乘法
    poly Mul(poly A,poly B,int len=0){
        int n=A.size(),m=B.size();
        if(len){
            if(n>len){
                A.resize(len),n=len;
            }
            if(m>len) B.resize(len),m=len;
        }
        if(n<=30||m<=30){
            poly res(n+m-1);
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    res[i+j]=(res[i+j]+A[i]*B[j]%mod)%mod;
                }
            }
            if(len){
                res.resize(len);
            }
            return res;
        }
        init(n,m);
        A.resize(limit);B.resize(limit);
        for(int i=min(n,m);i<limit;i++){
            if(i>=n) A[i]=0;
            if(i>=m) B[i]=0;
        }
        ntt(A,1);ntt(B,1);
        for(int i=0;i<limit;i++){
            A[i]=A[i]*B[i]%mod;
        }
        ntt(A,-1);
        if(len==0){
            A.resize(n+m-1);
        }
        else{
            A.resize(len);
        }
        return A;
    }
    //求导
    poly Direv(poly res){
        for(int i=1;i<(int)res.size();i++){
            res[i-1]=res[i]*i%mod;
        }
        res.pop_back();
        return res;
    }
    //积分
    poly Inter(poly res){
        int len=res.size();
        for(int i=len-1;i>=1;i--){
            res[i]=res[i-1]*ksm(i,mod-2,mod)%mod;
        }
        res[0]=0;
        return res;
    }
    //B(x)=2B'(x)-A(x)B'(x)B'(x) 
    poly GetInv(int n,poly &a){
        if(n==1){
            return {ksm(a[0],mod-2,mod)};
        }
        poly b=GetInv((n+1)>>1,a);
        poly c=a;
        int m=b.size();
        init(n,n);
        c.resize(limit);b.resize(limit);
        for(int i=m;i<limit;i++){
            b[i]=0;
        }
        for(int i=n;i<limit;i++){
            c[i]=0;
        }
        ntt(b,1);ntt(c,1);
        for(int i=0;i<limit;i++){
            c[i]=(2-c[i]*b[i]%mod+mod)%mod;
            c[i]=c[i]*b[i]%mod;
        }
        ntt(c,-1);
        c.resize(n);
        return c;
    }
    //多项式求逆
    poly Inv(poly a){
        int len=a.size();
        return GetInv(len,a);
    }
    //b'x=a'x/ax
    poly Ln(poly a){
        int n=a.size();
        a=Mul(Direv(a),Inv(a));
        a.resize(n);
        return Inter(a);
    }
    //gx=g'x(1-ln(g'x)+ax)
    poly Exp(int n,poly &a){
        if(n==1){
            return {1};
        }
        poly b=Exp((n+1)>>1,a);
        b.resize(n);
        for(int i=(n+1)>>1;i<n;i++) {
            b[i]=0;
        }
        poly e=Ln(b);
        poly c=a;
        init(n,n);
        b.resize(limit);e.resize(limit);c.resize(limit);
        for(int i=n;i<limit;i++){
            c[i]=e[i]=b[i]=0;
        }
        ntt(b,1);ntt(c,1);ntt(e,1);
        for(int i=0;i<limit;i++){
            c[i]=b[i]*((1-e[i]+mod+c[i])%mod)%mod;
        }
        ntt(c,-1);
        c.resize(n);
        return c;
    }
    poly Exp(poly a){
        return Exp((int)a.size(),a);
    }
    const int inv2=ksm(2,mod-2,mod);
    //g(x)=(f(x)+g'x*g'x)/(2*g'x)
}
using namespace Poly;
const int M=6e3+10;
ll fac[M], infac[M];
void init(int n=M-10){
    fac[0] = infac[0] = 1;
    for(int i = 1; i <= n; i ++){
        fac[i] = fac[i - 1] * i % mod;
    }
    infac[n] = ksm(fac[n], mod - 2,mod);
    for(int i = n; i >=1; i --){
        infac[i - 1] = infac[i] * i % mod;
    }
}

ll C(int n, int m){
    if(n < 0 || m < 0 || n < m) return 0;
    return fac[n] * infac[m] % mod * infac[n - m] % mod;
}

int f[M][M];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    init();
    int n, k;
    cin >> n >> k;
    if(k==1){
        cout<<(C(n+n,n)-C(n+n,n-1)+mod)%mod<<'\n';return 0;
    }
    ll ans = 0;
    f[0][0] = 1;
    for(int i = 0; i <  n; i ++){
        for(int j=0;j<=i;j++){
            int l=j,r=j+k;
            f[i+1][j]=(f[i+1][j]+f[i][j])%mod;
            if(r<=i+1) f[i+1][r]=(f[i+1][r]+mod-f[i][j])%mod;
        }
        for(int j=1;j<=i+1;j++){
            f[i+1][j]=(f[i+1][j]+f[i+1][j-1])%mod;
        }
        for(int j=0;j<=i+1;j++){
            if(j+k<=i+1){
                ans=(ans+f[i][j]*(C(n-i+n-j-k-1,n-i-1)-C(n-i+n-j-k-1,n-i-2)+mod)%mod)%mod;
            }
            else{
                break;
            }
        }
        
    }
    cout << ans << "\n";
    return 0;
}
