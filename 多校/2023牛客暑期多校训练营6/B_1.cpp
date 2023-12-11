#include<bits/stdc++.h>
using namespace std;
const int N=4e3+10,mod=998244353;
long long ksm(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
long long c[N][N];
long long sum[N][N];
void init(int n=N-10){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j==0||j==i) c[i][j]=1;
            else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
    int m=n/2;
    for(int i=0;i<=m;i++){
        for(int j=i;j<=m;j++){
            sum[i][j]=(c[i+j][i])%mod;
        }
    }


}
int s[N],t[N];
int n;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    sort(s+1,s+n+1);
    sort(t+1,t+n+1);
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            long long cnt=abs(s[i]-t[j]);
            int x=i-1,y=j-1,x1=n-i,y1=n-j;
            if(x>y) swap(x,y);if(x1>y1) swap(x1,y1);
            ans+=1ll*cnt*sum[x][y]%mod*sum[x1][y1]%mod;
            ans%=mod;
        }
    }
    cout<<ans;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
	solve();
	return 0;
}
