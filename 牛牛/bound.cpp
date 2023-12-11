#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);
#define int long long
using namespace std;
const int mod=1e9+7;
const int maxn=1e6;
int a[]={0,1,2,3,4,5,6,7,8,9,10};
int b[]={10,9,8,7,6,5,4,3,2,1,0};

void solve()
{
	int x;cin>>x;
	int fl;
	fl=lower_bound(a,a+13,x)-a;//在从小到大的序列中找出大于等于x的数的地址 
	fl=upper_bound(a,a+13,x)-a;//在从小到大的序列中找出大于x的书的地址
	
	fl=lower_bound(b,b+13,x,greater<int>() )-b;//在从大到小的序列中找出小于等于x的数的地址 
	fl=upper_bound(b,b+13,x,greater<int>() )-b;//在从小到大的序列中找出小于x的数的地址 
}

signed main()
{
	ios
	solve();
}