/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
	if(b==0)
	{
		x=1;y=0;
		return a;
	}
	long long d,x1,y2;
	d=exgcd(b,a%b,x1,y2);
	x=y2;
	y=x1-a/b*y2;
	return d;
}
long long gcd(long long a,long long b)
{
	return b?gcd(b,a%b):a;
}
int n,m;
vector<long long>a;
long long ans;
void check(int tp)
{
	long long res1=1,res2=1;
	for(int i=0;i<m;i++)
	{
		if((tp>>i)&1)
		{
			res1=res1*a[i];
		}
		else res2=res2*a[i];
	}
	long long x,y;
	long long d=exgcd(res2,-res1,x,y);
	long long k1=x/res1,k2=y/res2;
	if(x%res1==0||x<0) k1--;
	if(y%res2==0||y<0) k2--;
	long long k=min(k1,k2);
	y=y-res2*k;
	y*=res1;
	if(y%res1==0)
	ans=min(y,ans);
}
void solve()
{
	long long lc=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		if(lc==0) lc=x;
		else lc=lc/gcd(lc,x)*x;
	}
	lc*=2;
	ans=lc;
	for(int i=2;1ll*i*i<=lc;i++)
	{
		if(lc%i==0)
		{
			long long re=1;
			while(lc%i==0)
			{
				lc/=i;
				re=re*i;
			}
			a.push_back(re);
		}
	}
	if(lc!=1) a.push_back(lc);
	m=(int)a.size();
	for(int j=0;j<(1<<m);j++)
	{
		check(j);
	}
	cout<<ans;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}