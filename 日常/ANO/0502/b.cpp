#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int p[maxn];
int ans=0x3f3f3f3f;
int n;
int ok(int x,int y)
{
	int a=x,b=y;
	if(a<b)swap(a,b);
	if(a-b>=b)return INF;
	int t=a-b;b-=t;
	t+=b/3*2;b%=3;
	if(b==1)t++;
	else if(b==2)t+=2;
	return t;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];

	p[0]=p[n+1]=INF;
	for(int i=1;i<=n;i++)
	{
		int cnt=(p[i]+1)/2;
		if(i>1&&i<n)ans=min(ans,max(p[i-1],p[i+1]));
		int num=p[i-1]-cnt;
		ans=min(ans,cnt+(num>0?((num)/2+(num)%2):0));
		ans=min(ans,cnt+(num>0?((num)/2+(num)%2):0));
		ans=min(ans,ok(p[i],p[i-1]));
	}
	sort(p+1,p+1+n);
	ans=min(ans,p[1]/2+p[1]%2+p[2]/2+p[2]%2);
	cout<<ans<<endl;
}
/*
3
3 100 1

3
5 100 1
3

3
7 100 3
5

*/