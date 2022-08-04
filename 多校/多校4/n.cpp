/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int t[50];
int p[maxn];
int n;
void F(int x)
{
	vector<int>v;
	int y=0;
	while(x)
	{
		t[y++]+=x%2;
		x>>=1;
	}
}
void solve()
{
	cin>>n;
	double sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		sum+=p[i];
		F(p[i]);
	}
	sum=1.0*sum/n;

	vector<int>v;
	for(int i=1;i<=n;i++)
	{
		int s=0;
		int fl=0;
		for(int j=0;j<=15;j++)
		{	
			if(t[j])fl=1;
			if(t[j])s+=(1<<j),t[j]--;
			
		}
		if(!fl)break;
		v.push_back(s);
	}
	// for(auto y:v)
	// 	cout<<y<<" ";cout<<endl;

	int res=0;

	for(int i=0;i<n;i++)
	{
		if(i<v.size())
		{
			res+=(v[i]-sum)*(v[i]-sum);
		}
		else res+=sum*sum;
	}
	// cout<<res<<endl;


	int g=__gcd(res,n);
	res/=g;
	n/=g;
	cout<<res<<"/"<<n<<endl;










	
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
	return 0;
}