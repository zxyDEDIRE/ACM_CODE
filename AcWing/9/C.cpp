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
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int ans[maxn];
int p[maxn];
int a[maxn];
int b[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	stack<int>s;
	s.push(0);
	for(int i=1;i<=n;i++)
	{
		while(p[s.top()]>p[i])
			s.pop();
		a[i]=a[s.top()]+(i-s.top())*p[i];
		s.push(i);
	}
	while(s.size())s.pop();
	s.push(n+1);
	for(int i=n;i>=1;i--)
	{
		while(p[s.top()]>p[i])
			s.pop();
		b[i]=b[s.top()]+(s.top()-i)*p[i];
		s.push(i);
	}
	int ma=0,fl=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]+b[i]-p[i]>ma)
		{
			ma=a[i]+b[i]-p[i];
			fl=i;
		}
	}
	int mi=p[fl];
	for(int i=fl;i>=1;i--)
	{
		mi=min(mi,p[i]);
		ans[i]=mi;
	}
	mi=p[fl];
	for(int i=fl;i<=n;i++)
	{
		mi=min(mi,p[i]);
		ans[i]=mi;
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}