#include<bits/stdc++.h>
#define int long long
#define ios ios::sync_with_stdio(false);
using namespace std;
const int mod=1e9+7;
const int maxn=1e6+7;
int prime[maxn],phi[maxn];
bool vis[maxn];
int n;


void doit()
{
	for(int i=2;i<=maxn;i++){
		if(!vis[i])prime[++prime[0]]=i,phi[i]=i-1;
		for(int j=1;j<=prime[0]&&prime[j]*i<=maxn;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
}
signed main(){
	int n;cin>>n;
	doit();
	cout<<phi[n];
}
