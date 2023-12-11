#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
struct node{
	int step,x;
	bool operator<(const node&a)const{
		return a.step<step;
	}
};
int s,t;
void bfs()
{
	priority_queue<node>q;
	q.push({0,s});
	bitset<maxn>vis;
	while(!q.empty())
	{
		node now=q.top();q.pop();
		int step=now.step;
		int x=now.x;
		if(x<0)continue;
		if(x>100000)continue;
		if(vis[x])continue;
		if(x==t){cout<<now.step;return ;}
		vis[x]=1;
		q.push({step+1,x+1});
		q.push({step+1,x-1});
		q.push({step+1,x*2});
	}
}
int main()
{
	cin>>s>>t;
	bfs();
}