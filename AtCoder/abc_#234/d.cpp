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
const int maxn=1e6;
int p[maxn];
int a[maxn],cnt;
void solve()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=1;i<k;i++)
	{
		q.push(p[i]);
	}
	for(int i=k;i<=n;i++)
	{
		q.push(p[i]);
		if(q.size()>k)q.pop();
		cout<<q.top()<<endl;
	}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}