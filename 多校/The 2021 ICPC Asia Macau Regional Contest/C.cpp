#include<bits/stdc++.h>
using namespace std;
using ll=__int128;
namespace Poly{
    const int N=3e6+10;
    const ll mod=4179340454199820289;
    const ll g=3,gi=1393113484733273430;//根据模数不同改变原根
    using poly=vector<ll>;
    ll ksm(ll a,ll b,ll mod){
        ll res=1;
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
            ll wn=ksm(type==1?g:gi,(mod-1)/(mid<<1),mod);
            for(int j=0,R=mid<<1;j<limit;j+=R){
                ll w=1;
                for(int k=0;k<mid;k++,w=(w*wn)%mod){
                    ll x=v[j+k],y=v[j+mid+k]*w%mod;
                    v[j+k]=(x+y)%mod;
                    v[j+k+mid]=(x-y+mod)%mod;
                }
            }
        }
        if(type==-1){
            ll inv=ksm(len,mod-2,mod);
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
};
using namespace Poly;
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
void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	vector<int>v;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		h.push_back(vector<int>());
		dfs(i,h[tot]);
		v.push_back((int)h[tot].size());
		tot++;
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int t=(int)v.size();
	for(int i=0;i<(int)v.size();i++){
		id[v[i]]=i;
		ans[i].resize(v[i]);
		for(int j=0;j<v[i];j++){
			ans[i][j]=0;
		}
	}
	for(int i=0;i<(int)tot;i++){
		int len=(int)h[i].size();
		poly a(len+len,0);
		poly b(len,0);
		for(int j=0;j<len;j++){
			b[j]=a[j]=a[j+len]=h[i][j];
		}
		Reverse(b);
		a=Mul(a,b,len+len);
		for(int j=0;j<len;j++){
			ans[id[len]][j]+=a[j+len];
		}
	}
	for(int i=0;i<t;i++){
		reverse(ans[i].begin(),ans[i].end());
	}
	while(q--){
		int k;
		cin>>k;
		long long res=0;
		for(int j=0;j<t;j++){
			res+=ans[j][k%v[j]];
		}
		cout<<res<<'\n';
	}
}


int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}