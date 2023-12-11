/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn];
int n,k,sum;
void solve()
{
	cin>>n>>k;
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		q.push(x);
	}
	int sum=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		int x=q.front();q.pop();
		if(x+sum!=k)
		{
			sum+=x;
			p[++cnt]=x;
		}
		else
		{
			if(q.empty())
			{
				cout<<"NO\n"<<endl;
				return ;
			}
			else
			{
				int y=q.front();q.pop();
				sum+=y;
				p[++cnt]=y;
				q.push(x);
			}
		}
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=cnt;i++)
		cout<<p[i]<<" ";cout<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}