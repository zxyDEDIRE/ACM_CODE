#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=3e6+10,mod=998244353;
ll ksm(ll a,ll b,ll mod){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

int n;
int p[N];
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
const int g=3,gi=332748118;
using poly=vector<ll>;
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
	int len=(int)v.size();
	for(int i=0;i<len;i++){
		if(i<r[i]) swap(v[i],v[r[i]]);
	}
	for(int mid=1;mid<len;mid<<=1){
		ll wn=ksm(type==1?g:gi,(mod-1)/(mid<<1),mod);
		for(int j=0,R=mid<<1;j<limit;j+=R){
			ll w=1;
			for(int k=0;k<mid;k++,w=w*wn%mod){
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
poly Mul(poly A,poly B){
	int n=(int)A.size(),m=B.size();
	if(n<=30||m<=30){
		poly res(n+m-1);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				res[i+j]=(res[i+j]+A[i]*B[j]%mod)%mod;
			}
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
	A.resize(n+m-1);
	return A;
}
int num[N],cnt[N];
poly cale(int l,int r){
	if(l==r){
		poly res(cnt[l]+1);
		res[0]=1;
		for(int i=1;i<=cnt[l];i++){
			res[i]=res[i-1]*num[l]%mod;
		}
		for(int i=0;i<=cnt[l];i++){
			res[i]=res[i]*inv[i]%mod*inv[cnt[l]-i]%mod;
		}
		return res;
	}
	int mi=(l+r)>>1;
	poly c=Mul(cale(l,mi),cale(mi+1,r));
	return c;
}
void solve()
{
	cin>>n;
	vector<int>b;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		b.push_back(p[i]);
	}
	sort(p+1,p+n+1);
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	int m=(int)b.size();
	for(int i=1;i<=m;i++){
		num[i]=b[i-1];cnt[i]=0;
	}
	for(int i=1;i<=n;i++){
		int t=lower_bound(b.begin(),b.end(),p[i])-b.begin();
		cnt[t+1]++;
	}
	poly a=cale(1,m);
	long long fm=fac[n];
	for(int i=1;i<=m;i++){
		fm=fm*inv[cnt[i]]%mod;
	}
	long long res=0;;
	for(int i=1;i<=n;i++){
		res=(res+a[i]*fac[i]%mod*fac[n-i]%mod)%mod;
	}
	cout<<res*ksm(fm,mod-2,mod)%mod<<'\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	srand(time(0));
	int t;
	// t=1;
	cin>>t;
	init();
	while(t--){
		solve();
	}
	return 0;
}
/*
4
3
1 2 3
1
10
4
5 5 5 5
4
1 2 3 4
1076
*/