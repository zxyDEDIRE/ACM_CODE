#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int mod=1e9+7;
struct pp
{
	long long a,x;
}p[N];
int n;
bool cmp(pp x,pp y)
{
	return x.a<y.a;
}
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
int a[N],cnt;
void init()
{
	for(int i=0;i<=cnt;i++) a[i]=0;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].a>>p[i].x;
	}
	sort(p+1,p+n+1,cmp);
	long long tp=0;
	long long ans=1;
	long long res=0;
	long long r=p[1].a,l=p[1].a;
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i].a>r)
		{
			ans=ans*(res+1)%mod;
			res=0;
			init();cnt=0;
			r=p[i].a,l=p[i].a;
		}
		tp=ksm(2,p[i].a-l);
		res=(res+p[i].x*tp%mod)%mod;
		while(p[i].x)
		{
			if(p[i].x&1) a[p[i].a-l]++;
			if(p[i].x>1) p[i].a++;
			p[i].x/=2;
		}
		cnt=max(p[i].a,r)-l;
		for(int j=0;j<=cnt+32;j++)
		{
			a[j+1]+=a[j]/2;
			a[j]%=2;
			if(a[j+1]) cnt=max(cnt,j+1); 
		}
		r=l+cnt;
	}
	init();
	ans=ans*(res+1)%mod;
	cout<<ans;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve();
		if(i!=t) cout<<'\n';
	}
	return 0;
}
/*
1
6
1 1
2 2
3 3
7 1
8 2
9 3
*/