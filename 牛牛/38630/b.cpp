/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int x[100],y[100];
ll a,b,c;
int fp(int b,int p)
{
	int res=1;
	while(p)
	{
		if(p&1)res=(res*b);
		p>>=1;
		b=(b*b);
	}
	return res;
}
void solve()
{
	cin>>a>>b;
	int xx=0,yy=0;
	while(a)
	{
		x[++xx]=a%2;
		a/=2;
	}
	while(b)
	{
		y[++yy]=b%2;
		b/=2;
	}
	c=1;
	for(int i=0;i<63;i++)
	{
		if(x[i]&&y[i])c+=fp(2,i);
		else c+=fp(2,i);
	}
	cout<<c<<endl;
}
signed main(){
	 unsigned long long x;
	 x=(1ll<<63);
	 cout<<x<<endl;
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}