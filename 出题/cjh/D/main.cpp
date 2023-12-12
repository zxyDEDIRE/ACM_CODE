/*
狗头豪的数列求和
*/
/*
	平日里以下公式都是毕竟常见
	1+2..+n n*(n+1)/2
	1^2+2^2...n^2=n*(n+1)*(2*n+1)/6
	1^3+2^3...n^3=n^2*(n+1)^2/4
	那么 1^k+2^k+...n^k=?是多少呢
	求 前n项目 x^k 次方和 对 mod 取模
	n<=1e18 k<=10  mod<=2e9(mod不一定为质数)
*/

#include<bits/stdc++.h>
using namespace std;
const int N=15;
using ll=long long;
int k,mod;
long long n;
struct mat{
	int m;
	ll mp[N][N];
	mat(){
		memset(mp,0,sizeof(mp));
	}
	void re(){
		for(int i=0;i<m;i++){
			mp[i][i]=1;
		}
	}
	mat operator *(const mat &w)const{
		mat res;
		res.m=m;
		for(int k=0;k<m;k++){
			for(int i=0;i<m;i++){
				for(int j=0;j<m;j++){
					res.mp[i][j]+=mp[i][k]*w.mp[k][j]%mod;
					res.mp[i][j]%=mod;
				}
			}
		}
		return res;
	}
};

mat ksm(mat a,long long b){
	mat res;
	res.m=a.m;
	res.re();
	while(b){
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}

ll c[N][N];

void solve(){
	cin>>n>>k>>mod;
	int m=k+2;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=i;j++){
			if(i==j||j==0){
				c[i][j]=1;
			}
			else{
				c[i][j]=c[i-1][j-1]+c[i-1][j];
				if(c[i][j]>=mod) c[i][j]-=mod;
			}
		}
	}
	mat a;
	a.m=m;
	for(int j=m-1;j>=1;j--){
		a.mp[j][j]=1;
		int k1=k-j+1;
		for(int i=j+1,k2=k1-1,f=1;i<m;i++,k2--,f=mod-f){
			for(int p=i;p<m;p++){
				a.mp[p][j]+=f*c[k1][k2]%mod*a.mp[p][i];
				a.mp[p][j]%=mod;
			}
		}
	}
	a.mp[0][0]=1;
	for(int i=1;i<m;i++){
		a.mp[i][0]=a.mp[i][1];
	}
	mat res;
	res.m=m;
	for(int j=0;j<m;j++){
		res.mp[0][j]=1;
	}
	res=res*ksm(a,n-1);
	cout<<res.mp[0][0]<<'\n';
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
/*
n<=1e18 k<=10  mod<=2e9
*/

// long long ksm(long long a,long long b,long long mod){
// 	long long res=1;
// 	a%=mod;
// 	while(b){
// 		if(b&1) res=res*a%mod;
// 		a=a*a%mod;
// 		b>>=1;
// 	}
// 	return res;
// }
// void solve1(){
// 	long long ans=0;
// 	for(int i=1;i<=n;i++){
// 		ans=(ans+ksm(i,k,mod))%mod;
// 	}
// 	cout<<ans<<'\n';
// }