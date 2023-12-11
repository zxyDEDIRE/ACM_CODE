#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int q[N];
bool vis[N];
int u[N];
int cnt;
void init(int n){
	vis[1]=true;
	u[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			u[i]=i-1;
			q[cnt++]=i;
		}
		for(int j=0;1ll*q[j]*i<=n;j++){
			int nu=i*q[j];
			vis[nu]=true;
			if(i%q[j]==0){
				u[nu]=u[i]*q[j];
				break;
			}
			u[nu]=u[i]*u[q[j]];
		}
	}
}
long long ksm(long long a,long long b,long long mod){
	long long res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
const int mod=998244353;
set<int>s[30];
long long sum[N<<2];
long long la[N<<2];
void build(int k,int l,int r){
	la[k]=1;
	sum[k]=1;
	if(l==r){
		return;
	}
	int mi=(l+r)>>1;
	build(k<<1,l,mi);
	build(k<<1|1,mi+1,r);
	sum[k]=(sum[k<<1]+sum[k<<1|1])%mod;
}
void down(int k){
	if(la[k]!=1){
		la[k<<1]=la[k<<1]*la[k]%mod;
		la[k<<1|1]=la[k<<1|1]*la[k]%mod;
		sum[k<<1]=sum[k<<1]*la[k]%mod;
		sum[k<<1|1]=sum[k<<1|1]*la[k]%mod;
		la[k]=1;
	}
}
void mif(int k,int l,int r,int x,int y,long long val){
	if(l==x&&r==y){
		sum[k]=sum[k]*val%mod;
		la[k]=la[k]*val%mod;
		return;	
	}
	down(k);
	int mi=(l+r)>>1;
	if(y<=mi) mif(k<<1,l,mi,x,y,val);
	else if(mi<x) mif(k<<1|1,mi+1,r,x,y,val);
	else mif(k<<1,l,mi,x,mi,val),mif(k<<1|1,mi+1,r,mi+1,y,val);
	sum[k]=(sum[k<<1]+sum[k<<1|1])%mod;
}
long long qr(int k,int l,int r,int x,int y){
	if(l==x&&r==y){
		return sum[k];
	}
	down(k);
	long long ans=0;
	int mi=(l+r)>>1;
	if(y<=mi) ans=qr(k<<1,l,mi,x,y);
	else if(mi<x) ans=qr(k<<1|1,mi+1,r,x,y);
	else ans=(qr(k<<1,l,mi,x,mi)+qr(k<<1|1,mi+1,r,mi+1,y))%mod;
	sum[k]=(sum[k<<1]+sum[k<<1|1])%mod;
	return ans;
}
long long inv[N];
int vv[N],top;
void solve()
{
	init(100);
	int n,m;
	cin>>n>>m;
	build(1,1,n);
	for(int i=0;i<cnt;i++){
		inv[i]=ksm(q[i],mod-2,mod)*(q[i]-1)%mod;
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=0;j<cnt;j++){
			int res=0;
			while(x%q[j]==0){
				x/=q[j];
				res++;
			}
			if(res){
				mif(1,1,n,i,i,q[j]-1);
				res--;
				if(res){
					mif(1,1,n,i,i,ksm(q[j],res,mod));
				}
			}
			else{
				s[j].insert(i);
			}
		}
	}
	while(m--){
		int op,l,r,x;
		cin>>op>>l>>r;
		if(!op){
			cin>>x;
			mif(1,1,n,l,r,x);
			for(int j=0;j<cnt;j++){
				int res=0;
				long long vl=inv[j];
				if(x%q[j]==0){
					auto t=s[j].lower_bound(l);
					top=0;
					while(t!=s[j].end()){
						int v=*t;
						if(v>r) break;
						mif(1,1,n,v,v,vl);
						vv[++top]=v;t++;
					}
					for(int o=top;o>=1;o--){
						s[j].erase(vv[o]);
					}
				}
			}
		}
		else{
			cout<<qr(1,1,n,l,r);
			if(m) cout<<'\n';
		}
	}
}
/*
5 1
1 1 1 1 1
1 1 5
*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __=1;
	// cin>>__;
	while(__--)
		solve();
	return 0;
}