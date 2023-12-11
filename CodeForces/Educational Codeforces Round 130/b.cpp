#include<bits/stdc++.h>
#define int long long 
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn],dp[maxn];
int n,q,x,y;
bool cmp(int a,int b){
	return a>b;
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n,cmp);
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=p[i]+dp[i-1];
	}
	while(q--)
	{
		cin>>x>>y;
		cout<<dp[x]-dp[x-y]<<"\n";
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    solve();
    return 0;
}
//5 5  3  2  1
//5 10 13 15 16