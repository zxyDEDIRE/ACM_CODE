#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int a[maxn];
int b[maxn];
void solve()
{
	int n;
	cin>>n;
	while(n--)
	{
		int op,x;
		cin>>op>>x;
		if(op==1)
		{
			if(x<0)a[0]++,x=-x;
			for(int j=2;j*j<=x;j++)
				if(x%j==0){
					while(x%j==0)
						a[j]++,x/=j;
				}
			if(x!=1)a[x]++;
		}
		else
		{
			if(x<0)a[0]--,x=-x;
			for(int j=2;j*j<=x;j++)
				if(x%j==0){
					while(x%j==0)
						a[j]--,x/=j;
				}
			if(x!=1)a[x]--;
		}
	}

	cin>>n;
	while(n--)
	{
		int op,x;
		cin>>op>>x;
		if(op==1)
		{
			if(x<0)b[0]++,x=-x;
			for(int j=2;j*j<=x;j++)
				if(x%j==0){
					while(x%j==0)
						b[j]++,x/=j;
				}
			if(x!=1)b[x]++;
		}
		else
		{
			if(x<0)b[0]--,x=-x;
			for(int j=2;j*j<=x;j++)
				if(x%j==0){
					while(x%j==0)
						b[j]--,x/=j;
				}
			if(x!=1)b[x]--;
		}
	}
	for(int i=0;i<=1e5;i++)
		if(a[i]!=b[i]){
			cout<<"NO\n";
			return ;
		}
	cout<<"YES\n";
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}