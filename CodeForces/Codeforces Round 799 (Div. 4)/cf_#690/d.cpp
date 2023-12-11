#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn],a[maxn];
int n,sum;
void solve()
{
	cin>>n;
	sum=0;
	for(int i=1;i<=n;i++)
		cin>>p[i],sum+=p[i];
	int mi=n-1;
	for(int i=n;i>=1;i--)
	{
		if(sum%i!=0)continue;
		int flag=1;
		int t=sum/i;
		int s=0;
		for(int j=1;j<=n;j++)
		{
			s+=p[j];
			if(s==t)s=0;
			if(s>t){
				flag=0;
				break;
			}
		}
		if(s!=0)flag=0;
		if(flag){
			cout<<n-i<<endl;
			return ;
		}
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}