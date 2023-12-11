#include<bits/stdc++.h>
using namespace std;
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
};
namespace FFT{
    using poly=vector<complex_>;
    int limit,top;
    const int N=3e6+10;
    int r[N];
    void init(int n,int m){
        limit=1;top=0;
        while(limit<=n+m) limit<<=1,top++;
        for(int i=0;i<limit;i++){
            r[i]=(r[i>>1]>>1)|((i&1)<<(top-1));
        }
    }
    void fft(poly &v,int type){
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
                v[i].a/=(double)len;
            }
        }
    }
     poly Mul(poly A,poly B,int len=0){
         int n=A.size(),m=B.size();
        if(len){
            if(n>len){
                A.resize(len),n=len;
            }
            if(m>len) B.resize(len),m=len;
        }
        if(n<=30||m<=30){
            poly res(n+m-1,{0,0});
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    res[i+j].a=(res[i+j].a+A[i].a*B[j].a);
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
            if(i>=n) A[i].a=A[i].b=0;
            if(i>=m) B[i].a=B[i].b=0;
        }
        fft(A,1);fft(B,1);
        for(int i=0;i<limit;i++){
            A[i]=A[i]*B[i];
        }
        fft(A,-1);
        if(len==0){
            A.resize(n+m-1);
        }
        else{
            A.resize(len);
        }
        return A;
     }
     //反转多项式系数
    void Reverse(poly &a){
        reverse(a.begin(),a.end());
    }
}
using namespace FFT;
bool vis[N];
int p[N];
int n;
vector<vector<int>>h;
int tot=0;
void dfs(int x,vector<int>&list)
{
	list.push_back(x);
	vis[x]=true;
	if(!vis[p[x]])
		dfs(p[x],list);
}
int id[N];
const int M=1e5+10;
vector<long long>ans[M];
int q;
void pr(__int128 t){
    if(t>=10) pr(t/10);
    cout<<char('0'+t%10);
}
__int128 ksm(__int128 a,__int128 b,__int128 mod){
    __int128 res=1;
    a%=mod;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
__int128 mod=4179340454199820289ll;
void solve(){
    __int128 t=ksm(3,mod-2,mod);
	pr(t);
}


int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}