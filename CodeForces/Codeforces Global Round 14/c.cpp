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
struct node{
	int x,y;
	bool operator<(const node&a)const{
		return a.x<x;
	}
};
int id[maxn];
int p[maxn];
int n,m,x;
void solve()
{
	priority_queue<node>q;
	cin>>n>>m>>x;
	for(int i=1;i<=m;i++)
		q.push({0,i});
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		auto [x,y]=q.top();q.pop();
		id[i]=y;
		q.push({x+p[i],y});
	}
	int mi=1e9,ma=0;
	while(!q.empty())
	{
		auto [x,y]=q.top();q.pop();
		mi=min(mi,x);
		ma=max(ma,x);
	}
	if(ma-mi>x)cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)
			cout<<id[i]<<" ";cout<<endl;
	}
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