/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<iostream>
using namespace std;
// using ll=long long;
// using pii=pair<int,int>;
const int maxn=1e6;
int q[maxn],p[maxn];
int n,k,s,t;
void MIN()
{
	s=0,t=0;
	for(int i=1;i<k;i++)
	{
		while(s<=t&&p[q[t]]>=p[i])t--;
		q[++t]=i;
	}
	for(int i=k;i<=n;i++)
	{
		while(s<=t&&p[q[t]]>=p[i])t--;
		q[++t]=i;
		while(q[s]<=i-k)s++;
		cout<<p[q[s]]<<" ";
	}
	cout<<endl;
}
void MAX()
{
	s=0,t=0;
	for(int i=1;i<k;i++)
	{
		while(s<=t&&p[q[t]]<=p[i])t--;
		q[++t]=i;
	}
	for(int i=k;i<=n;i++)
	{
		while(s<=t&&p[q[t]]<=p[i])t--;
		q[++t]=i;
		while(q[s]<=i-k)s++;
		cout<<p[q[s]]<<" ";
	}
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i];

	MIN();
	MAX();
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
		solve();
	return 0;
}