/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
const int maxn=1e6+100;
const int M=5e5+100;
ll F[M],INF[M];
int p[maxn];
int a[maxn];
int n,m;
ll ksm(ll b,ll p){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}

void solve()
{
	cin>>m;n=1<<m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	a[1]=1;
	int s=1,t=0;
	for(int i=2;i<=n;i++)
	{
		a[i]=s;
		t++;if(t==s)s*=2,t=0;
	}
	for(int i=1;i<=n;i++)
		a[i]*=4;
	vector<int>v(n+1);
	for(int i=1;i<=n;i++)
		if(p[i]==-1)v[i]=0;
		else v[i]=a[p[i]];
	ll ans=1;
	for(int step=m;step>1;step--)
	{
		int cnt=0;
		vector<int>u(1);
		// for(int i=1;i<=n;i++)
		// 	cout<<v[i]<<" ";cout<<endl;
		for(int i=1;i<=n;i+=2)
		{
			if(v[i]==0&&v[i+1]==0)ans=(ans*2)%mod,u.push_back(0);
			else if(v[i]==n*2&&v[i+1]==n*2){
				cout<<0<<endl;
				exit(0);
			}
			else if(v[i]!=0&&v[i]<n*2&&v[i+1]!=0&&v[i+1]<n*2)
			{
				// cout<<"SDf"<<endl;
				cout<<0<<endl;
				exit(0);
			}
			else if(v[i]==n*2)u.push_back(v[i+1]),cnt++;
			else if(v[i+1]==n*2)u.push_back(v[i]),cnt++;
			else if(v[i]!=0&&v[i]<n*2)u.push_back(v[i]);
			else if(v[i+1]!=0&&v[i+1]<n*2)u.push_back(v[i+1]);

			// if(v[i]==0&&v[i+1]==0)ans=(ans*2)%mod,u.push_back(0);




		}
		// cout<<ans<<" "<<cnt<<endl;
		n/=2;
		ans=(ans*F[n-cnt])%mod;
		v.resize(1+(n));
		// for(int i=1;i<=n;i++)
		// 	cout<<u[i]<<" ";cout<<endl;
		for(int i=1;i<=n;i++)
			v[i]=u[i];
	
		// cout<<ans<<endl;
		// cout<<endl;
	}
	// cout<<v[1]<<" "<<v[2]<<endl;
	if(v[1]==0&&v[2]==0)ans=(ans*2)%mod;
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	F[0]=INF[0]=1;
	for(int i=1;i<M;i++)
	{
		F[i]=F[i-1]*i%mod;
		INF[i]=ksm(F[i],mod-2);
	}
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
4
3 -1 -1 11 15 -1 10 7 6 -1 16 2 4 -1 5 9
8 0 0 32 32 0 32 16 16 0 32 4 8 0 16 32
8 0 0 16 16 4 8 16
A:  95.8 (01:35.7) of 192.0 (03:12.0) 12.8%
*/