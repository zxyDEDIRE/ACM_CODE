/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
ll c[maxn];
ll b[maxn];
ll a[maxn];
ll n,m;
void NO(){cout<<"NO"<<endl;}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=(n+1)/2;i++)
	{
		ll s=c[i]+c[n-i+1];
		if((s&1)&&(m%2==0))return NO();
		if(s&1)
		{
			a[i]=(s+m)/2;
			a[i]=(a[i]%m+m)%m;
			a[n-i+1]=a[i];

			b[i]=((c[i]-a[i])%m+m)%m;
			b[n-i+1]=((-b[i])%m+m)%m;
			// b[i]=(c[i]-a[i]);
			// b[n-i+1]=-b[i];
		}
		else
		{
			a[i]=s/2;
			a[i]=(a[i]%m+m)%m;
			a[n-i+1]=a[i];

			b[i]=((c[i]-a[i])%m+m)%m;
			b[n-i+1]=((-b[i])%m+m)%m;
			// b[i]=(c[i]-a[i]);
			// b[n-i+1]=-b[i];
		}
	}
	// cout<<"YES"<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<a[i]<<" ";cout<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<b[i]<<" ";cout<<endl;
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<a[i];
		if(i!=n)cout<<" ";
		else cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<b[i];
		if(i!=n)cout<<" ";
		else cout<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
12
1 2 3 4 5
3 3 3 3 3
9 10 0 1 2

x+y=7%10
x-y=7%10
1 6


7 %10
2
2
*/