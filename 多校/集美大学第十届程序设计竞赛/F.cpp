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
#define double long double 
const double PI=acos(-1);
struct complex_{
    double a,b;
    complex_(){a=0;b=0;}
    complex_(double _a,double _b){a=_a;b=_b;}
    complex_ operator +(const complex_ &w)const{
        return complex_(a+w.a,b+w.b);
    }
    complex_ operator -(const complex_ &w)const{
        return complex_(a-w.a,b-w.b);
    }
    complex_ operator *(const complex_ &w)const{
        return complex_(a*w.a-b*w.b,a*w.b+b*w.a);
    }
    complex_ operator /(const double w){
        return complex_(a/w,b/w);
    }
};
namespace MTT{
    using poly=vector<long long>;
    using poly1=vector<complex_>;
    const int N=3e6+10;
    const long long B=(1<<15);
    const complex_ I(0,1);
    int mod=1e9+7;
    int r[N],limit,L;
    void init(int n,int m){
        limit=1;L=0;
        while(limit<=n+m) limit<<=1,L++;
        for(int i=0;i<limit;i++){
            r[i]=(r[i>>1]>>1)|((i&1)<<(L-1));
        }
    }
    void fft(poly1 &v,int type){
        int len=v.size();
        for(int i=0;i<len;i++){
            if(i<r[i]) swap(v[i],v[r[i]]);
        }
        for(int mid=1;mid<len;mid<<=1){
            complex_ wn(cos(PI/mid),type*sin(PI/mid));
            for(int R=mid<<1,j=0;j<len;j+=R){
                complex_ w(1,0);
                for(int k=0;k<mid;k++,w=w*wn){
                    complex_ x=v[j+k],y=w*v[j+k+mid];
                    v[j+k]=x+y;
                    v[j+k+mid]=x-y;
                }
            }
        }
        if(type==-1){
            for(int i=0;i<len;i++){
                v[i]=v[i]/(double)len;
            }
        }
    }
    void mtt(poly1 &a,poly1 &b){
        for(int i=0;i<limit;i++){
            a[i].b=b[i].a;
        }
        fft(a,1);
        b[0]=complex_(a[0].a,-a[0].b);
        for(int i=1;i<limit;i++){
            b[i]=complex_(a[limit-i].a,-a[limit-i].b);
        }
        complex_ t1,t2;
        for(int i=0;i<limit;i++){
            t1=a[i],t2=b[i];
            a[i]=(t1+t2)/2.0;
            b[i]=(t2-t1)*I/2.0;
        }
    }
    long long rd(const double x){
        if(x>=0) return (long long)(x+0.5)%mod;
        return (long long)(x-0.5)%mod;
    }
    poly Mul(poly a,poly b,int len=0){
        int n=(int)a.size(),m=(int)b.size();
        if(len){
            if(n>=len){
                n=len;
            }
            if(m>=len){
                m=len;
            }
        }
        if(n<=30||m<=30){
            poly res(n+m-1);
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    res[i+j]=(res[i+j]+a[i]*b[j]%mod)%mod;
                }
            }
            if(len){
                res.resize(len);
            }
            return res;
        }
        if(len){
            init(len,len);
        }else{
            init(n,m);
        }
        a.resize(n+m-1);
        poly1 a0(limit),b0(limit),a1(limit),b1(limit);
        for(int i=0;i<limit;i++){
            a0[i]=a1[i]=complex_(0,0);
            if(i<n){
                a1[i].a=a[i]%B;
                a0[i].a=a[i]/B;
            }
        }
        for(int i=0;i<limit;i++){
            b0[i]=b1[i]=complex_(0,0);
            if(i<m){
                b1[i].a=b[i]%B;
                b0[i].a=b[i]/B;
            }
        }
        mtt(a0,a1);mtt(b0,b1);
        complex_ t1,t2;
        for(int i=0;i<limit;i++){
            t1=a0[i]*b0[i]+I*a1[i]*b0[i];
            t2=a0[i]*b1[i]+I*a1[i]*b1[i];
            a0[i]=t1;b0[i]=t2;
        }
        fft(a0,-1);fft(b0,-1);
        for(int i=0;i<n+m-1;i++){
            long long ans=1ll*B*B%mod*rd(a0[i].a)%mod+
            1ll*B*rd(b0[i].a+a0[i].b)%mod+rd(b0[i].b)%mod;
            a[i]=(ans+mod)%mod;
        }
        if(len) a.resize(len);
        return a;
    }
     //反转多项式系数
    void Reverse(poly &a){
        reverse(a.begin(),a.end());
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
        c=Mul(c,b,n);
        for(int i=0;i<n;i++){
            c[i]=(mod-c[i])%mod;
        }
        c[0]=(c[0]+2)%mod;
        c=Mul(c,b,n);
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
        for(int i=(n+1)>>1;i<n;i++){
            b[i]=0;
        }
        poly e=Ln(b);
        for(int i=1;i<n;i++){
            e[i]=(-e[i]+mod+a[i])%mod;
        }
        e[0]=(1-e[0]+mod+a[0])%mod;
        e=Mul(e,b,n);
        return e;
    }
    poly Exp(poly a){
        return Exp((int)a.size(),a);
    }
}
using namespace MTT;
const int M=1e5+10;
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
int n,m;
int k[M];
poly ct[M];
poly cale(int l,int r,int x){
    if(l==r){
        if(l==x){
            poly res(1,1);
            return res;
        }
        poly res(k[l]+2,1);
        res[k[l]+1]=mod-1;
        return res;
    }
    int mi=(l+r)>>1;
    return Mul(cale(l,mi,x),cale(mi+1,r,x));
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        ct[i].resize(k[i]+1,0);
        for(int j=1;j<=k[i];j++){
            cin>>ct[i][j];
        }
    }
    cin>>m;
    long long ans=0;
    for(int i=1;i<=n;i++){
        poly a=cale(1,n,i);
        for(int j=1;j<=k[i];j++){
            int t=m-j;
            if(t<0) break;
            ans=(ans+ct[i][j]*a[t]%mod*C(n-2+t,n-2)%mod)%mod;
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}