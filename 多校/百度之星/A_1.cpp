#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6+100;
int p[3][maxn];
int pre[maxn];
int n;
bool check(int x,int i,int fl)
{
	return abs(p[fl][x]-p[fl][i])<=abs(x-i);
}
int A(int x,int fl)
{
	int l=1,r=x,ans=r;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(x,mid,fl))ans=mid,r=mid;
		else l=mid;
	}
	if(ans>1&&check(x,ans-1,fl))ans--;
	return ans;
}
int B(int x,int fl)
{
	int l=x,r=n,ans=l;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(x,mid,fl))ans=mid,l=mid;
		else r=mid;
	}
	if(ans<n&&check(x,ans+1,fl))ans++;
	return ans;
}
ll f(ll sum,int i,int fl)
{
	// cout<<sum<<" "<<i<<" "<<fl<<endl;
	int len_1 = i-1;
	int len_2 = n-i;

	int l1=A(i,fl);
	int l2=B(i,fl);
	// cout<<l1<<" "<<l2<<endl;
	// cout<<sum<<endl;
	ll now=sum - 1ll*(l1-1+1)*(l1-1)/2 - 1ll*(n-l2+1)*(n-l2)/2;
	// cout<<now<<endl;

	ll _sum1=0,_sum2=0;
	_sum1 = pre[i-1]-pre[l1-1];
	_sum2 = 1ll*(p[fl][i])*(i-l1) - 1ll*(i-l1+1)*(i-l1)/2;
	now += abs(_sum2-_sum1);
	now = now - (_sum1 - 1ll*(p[fl][i])*(i-l1));
	// cout<<now<<endl;

	_sum1 = pre[l2]-pre[i];
	// cout<<"len "<<l2-i<<endl;
	_sum2 = 1ll*(p[fl][i])*(l2-i) + 1ll*(l2-i+1)*(l2-i)/2;
	now += abs(_sum1 - _sum2);
	now = now - (_sum1 - 1ll*(p[fl][i])*(l2-i));
	// cout<<now<<endl;
	// cout<<endl;


	// exit(0);
	return now;
}
pair<ll,ll> doit(int fl)
{
	sort(p[fl]+1,p[fl]+1+n);
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+p[fl][i];
	ll ans1=0,ans2=0;
	ll sum=0;
	for(int i=2;i<=n;i++)
		sum+=p[fl][i]-p[fl][1];
	ans1=sum;ans2=f(sum,1,fl);
	for(int i=2;i<=n;i++)
	{
		sum = sum-1ll*(n-i+1)*(p[fl][i]-p[fl][i-1]) + 1ll*(i-1)*(p[fl][i]-p[fl][i-1]);
		ans2=min(ans2,f(sum,i,fl));
		ans1=min(ans1,sum);
	}
	return {ans1,ans2};
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++)
			cin>>p[j][i];
	pair<ll,ll>a[3];
	for(int j=0;j<3;j++){
		a[j]=doit(j);
		// cout<<a[j].first<<" "<<a[j].second<<endl;
	}
	ll A = a[0].first + a[1].first + a[2].second;
	ll B = a[0].first + a[1].second + a[2].first;
	ll C = a[0].second + a[1].first + a[2].first;
	cout<<min({A,B,C})<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
/*
4
0 0 0
0 0 0
0 0 0
0 0 0
*/