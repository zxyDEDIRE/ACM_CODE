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
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct node{
	int x,y;
};
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	stack<node>q;
	for(int i=1;i<=n;i++)
	{
		if(q.empty())q.push({p[i],1});
		else
		{
			{
				auto [x,y]=q.top();
				//cout<<i<<" "<<x<<" "<<y<<endl;
				if(x!=p[i])q.push({p[i],1});
				else if(x==p[i])q.push({x,y+1});
			}
			

			{
				auto [x,y]=q.top();
				//cout<<i<<" "<<x<<" "<<y<<endl;
				if(x==y)
				{
					for(int j=1;j<=y;j++)
						q.pop();
				}
			}
			
		}
		cout<<q.size()<<endl;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
	return 0;
}