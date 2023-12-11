#include<bits/stdc++.h>
using namespace std;

const int N=2e2+10,M=1e5+10,mod=998244353;
long long ksm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int n,m;
int a[N],b[N];
long long dp[N],ddp[N];
long long pd[N][N][N];
int num[N];
void solve()
{
// 	cin>>n>>m;
    n=200;m=1e5;
    for(int i=1;i<=n;i++)
    {
//         cin>>a[i]>>b[i];
        a[i]=rand()%201;b[i]=rand()%201;
    }
    for(int l=1;l<=n;l++)
    {
        for(int r=l;r<=n;r++)
        {
            for(int j=0;j<=200;j++)
            {
                pd[l][r][j]=pd[l][r-1][j];
            }
            for(int j=200;j>=a[r];j--)
            {
                pd[l][r][j]=max(pd[l][r][j],pd[l][r][j-a[r]]+b[r]);
            }
        }
    }
    vector<int>si;
    for(int i=1;i<=m;i++)
    {
        int x;
//         cin>>x;
        x=rand()%201;
        num[x]++;
        num[x]=min(num[x],200);
        si.push_back(x);
    }
    sort(si.begin(),si.end());
    si.erase(unique(si.begin(),si.end()),si.end());
    sort(si.begin(),si.end(),[&](int x,int y){
        return x>y;
    });
    for(int i=0;i<si.size();i++)
    {
        int sii=si[i];
        for(int k=1;k<=num[sii];k++)
        {
            for(int j=0;j<=n;j++)
            {
                ddp[j]=dp[j];
            }
            for(int l=n-i-k+1;l>=1;l--)
            {
                for(int r=l;r>=1;r--)
                 ddp[r]=max(ddp[r],dp[l+1]+pd[r][l][sii]);
            }
            for(int j=0;j<=n;j++){
                dp[j]=ddp[j];
            }
        }
    }
    cout<<dp[1];
    
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		clock_t start, finish;
	start = clock();
	/*******代码*******/
	solve();
	/****************/
	finish = clock();
	cout << "the time cost is" <<\
	double(finish - start) / CLOCKS_PER_SEC;}
	return 0;
}
