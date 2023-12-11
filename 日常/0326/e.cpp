#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6;
int p[maxn];
int n;
void solve(int l,int r,int step)
{
	if(l==r)return ;
	int a=l;
	int b=(l+r)/2+1;
	if(!b)return ;
	if(step%2==0) p[b]=p[a]^1;
	else p[b]=p[a];
	if(l<=b-1)solve(l,b-1,step+1);
	if(b<=r)solve(b,r,step+1);
}
signed main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n;
	int len=pow(2,n);
	solve(1,len,1);
	p[1]=0,p[len/2+1]=1;
	for(int i=1;i<=len;i++)
		cout<<p[i];
}
//13:20-17:30
//7:00-9:40;
/*
0110 1001 1001 0110
*/