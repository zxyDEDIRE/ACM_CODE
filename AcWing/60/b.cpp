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
void solve()
{
	priority_queue<int,vector<int>,greater<int> >q;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		if(x)q.push(x);
	}
	int s=0;
	for(int i=0;i<k;i++)
	{
		int ans=-1;
		while(1)
		{
			if(q.empty())break;
			int x=q.top();q.pop();
			x-=s;
			if(x>0)
			{
				ans=x;
				s+=x;
				break;
			}
		}
		if(ans!=-1)cout<<ans<<endl;
		else cout<<0<<endl;
	}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}