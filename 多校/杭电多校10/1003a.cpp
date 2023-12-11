/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int a[maxn],b[maxn];
int p[maxn];
int n;
int A()//di gao di
{
	int ans=0;
	for(int i=1;i<n;i++)
	{
		if(i&1)//di
		{
			if(p[i+1]<=p[i])
			{
				ans+=p[i]-p[i+1]+1;
				p[i+1]=p[i]+1;
			}
		}
		else
		{
			if(p[i+1]>=p[i])
			{
				ans+=p[i+1]-p[i]+1;
				p[i+1]=p[i]-1;
			}
		}
	}
	return ans;
}
int B()//gao di gao
{
	int ans=0;
	for(int i=1;i<n;i++)
	{
		if(i&1)//gao
		{
			if(a[i+1]>=a[i])
			{
				ans+=a[i+1]-a[i]+1;
				a[i+1]=a[i]-1;
			}
		}
		else
		{
			if(a[i+1]<=a[i])
			{
				ans+=a[i]-a[i+1]+1;
				a[i+1]=a[i]+1;
			}
		}
	}
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i],a[i]=p[i];
	cout<<min(A(),B())<<endl;
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1 1 4 5 1 4
0 1 0 5 1 4
1 5 4 5 1 4

1 2 3 4
1 2 3 4
*/