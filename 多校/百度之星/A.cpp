#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6+6;
ll sum1[maxn],sum2[maxn],sum3[maxn];
int a[maxn],b[maxn],c[maxn];
int n;
bool check(int x,int i,int fl)
{
	if(fl==1)return abs(a[x]-a[i])<=abs(x-i);
	if(fl==2)return abs(b[x]-b[i])<=abs(x-i);
	if(fl==3)return abs(c[x]-c[i])<=abs(x-i);
}
int A(int x,int fl)
{
	int l=1,r=x-1,ans=r;
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
	int l=x+1,r=n,ans=l;
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
	int len_1 = i-1;
	int len_2 = n-i;

	int l1=A(i,fl);
	int l2=B(i,fl);
	ll now=sum - (l1-1+1)*(l1-1)/2 - (n-l2+1)*(n-l2)/2;
	ll _sum1=0,_sum2=0;
	


}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i]>>c[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	sort(c+1,c+1+n);
	for(int i=1;i<=n;i++)
	{
		sum1[i]=sum1[i-1]+a[i];
		sum2[i]=sum2[i-1]+b[i];
		sum3[i]=sum3[i-1]+c[i];
	}
	ll sum_a=0,sum_b=0,sum_c=0;

	for(int i=2;i<=n;i++)
	{
		sum_a+=a[i]-a[1];
		sum_b+=b[i]-b[1];
		sum_c+=c[i]-c[1];
	}
	ll mi_a=sum_a,mi_b=sum_b,mi_c=sum_c;
	ll _mia=f(sum_a,1,1),_mib=f(sum_b,1,2),_mic=f(sum_c,1,3);
	for(int i=2;i<=n;i++)
	{
		sum_a = sum_a-(n-i+1)*(a[i]-a[i-1]) + (i-1)*(a[i]-a[i-1]);
		sum_b = sum_b-(n-i+1)*(b[i]-b[i-1]) + (i-1)*(b[i]-b[i-1]);
		sum_c = sum_c-(n-i+1)*(c[i]-c[i-1]) + (i-1)*(c[i]-c[i-1]);
		mi_a = min(mi_a,sum_a);
		mi_b = min(mi_b,sum_b);
		mi_c = min(mi_c,sum_c);

		_mia=min(_mia, f(sum_a,i,1));
		_mib=min(_mib, f(sum_b,i,2));
		_mic=min(_mic, f(sum_c,i,3));
	}
	cout<<min({mi_a+mi_b+_mic,mi_a+_mib+mi_c,_mia+mi_b+mi_c})<<endl;

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