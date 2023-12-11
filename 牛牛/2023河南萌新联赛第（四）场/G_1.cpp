/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=1e9+7;
const int maxn=1e6+100;
const int M=2e5+100;
int F[M],INF[M];
int p[maxn];
int n,k;
int ksm(int b,int p){int r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}

int C(int n,int m){
	// mod
	if(m>n)return 1;
	return ((F[n]*INF[n-m])%mod*INF[m])%mod;  //mod
	
}
int a[maxn];
signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>p[i],a[i]=i;
    vector<vector<int>>v;
    do{
        vector<int>w;
        for(int i=1;i<=k;i++)
            w.push_back(a[i]);
        sort(w.begin(),w.end());
        for(auto &x:w)
            x=p[x];
        v.push_back(w);
    }while(next_permutation(a+1,a+1+n));
    
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    cout<<v.size()<<endl;
	return 0;
}
/*
1
9 2
1 2 3 10 3 4 5 6 7
31

1
4 2
1 1 2 3



*/