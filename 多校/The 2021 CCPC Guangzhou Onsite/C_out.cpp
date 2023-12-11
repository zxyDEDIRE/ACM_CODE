/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
using ll=long long;

const ll INF=1e18+7;
const int maxn=1e6+100;
ll p[maxn];
ll n;
ll m;
inline void read(ll &x){
   ll s = 0, w = 1; char ch = getchar();
   while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar(); }
   while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
   x = s*w;
   return ;
}

bool check(ll mid)
{
	ll r=min(p[0]+mid-1,p[1]-1);
	ll ans=r-mid+1;
	ll MI=r-p[0];

	// cout<<"r0 :"<<r<<endl;
	// cout<<"MA0 :"<<MI<<endl;
	// cout<<"ans0 :"<<ans<<endl;
	for(int i=1;i<m-1;i++)
	{
		ll l=r+1;
		r=min(l+mid-1,p[i+1]-1);
		// cout<<"L: "<<l<<" R: "<<r<<endl;
		if(r<p[i])return false;
		if(r-p[i]<MI)
			ans-=(MI-(r-p[i])),MI=r-p[i];
	}
	ll l=r+1;
	r=(l+mid-1);
	if(r<p[m-1])return false;
	MI=min(MI,mid-(r-l+1));
	// cout<<"L: "<<l<<" R: "<<r<<endl;
	// cout<<"ans :"<<ans<<endl;
	ans-=MI;
	r-=n;
	if(r>=ans-1)return true;
	return false;	
}
void solve()
{
	read(n);read(m);
	if(m==1){
		printf("%lld",n);
		return ;
	}
	for(int i=0;i<m;i++)
		read(p[i]);
	ll l=(n+m-1)/m,r=(n+1)/2;
	int cnt=0;
	while(l<r)
	{
		cnt++;
		ll mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<cnt<<endl;
	printf("%lld",r);
}
signed main(){
 freopen("C:\\Users\\tob\\Desktop\\out.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		clock_t start, finish;
	start = clock();
	/*******代码*******/
	solve();
	/****************/
	finish = clock();
	cout << "the time cost is" <<\
	double(finish - start) / CLOCKS_PER_SEC;
 fclose(stdin);
 // fclose(stdout);
	return 0;
}