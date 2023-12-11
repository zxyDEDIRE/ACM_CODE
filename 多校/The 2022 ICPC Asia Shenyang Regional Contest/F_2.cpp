#include<bits/stdc++.h>
using namespace std;
const int N=100;
int mp[N][N];
int n,m;

long long get(long long n)
{
	return n*(n+1)/2;
}

signed main()
{
	cin>>n>>m;
	long long tp=get(n)*(get(m));
	int len=m/2;
	int a=get(n)*get(len);
	int b=get(n)*get(m-len-1);
	int c=get(n)*1;
	cout<<tp<<" "<<tp/2<<endl;
	cout<<a<<" "<<b<<" "<<c<<" "<<a+b+c<<endl;
}
