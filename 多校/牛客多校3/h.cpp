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
struct node{
	int x,y,step;
	bool operator<(const node&a)const{
		return a.step<step;
	}
};
vector<int>v[maxn];
map<pii,bool>vis;
int p[10];
int n,sx,sy,tx,ty;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=4;j++)
		{
			int x;cin>>x;
			v[i].push_back(x);
			//v[x].push_back(i);
		}
	}
	cin>>sx>>sy>>tx>>ty;
	priority_queue<node>q;
	q.push({sx,sy,0});
	while(!q.empty())
	{
		auto [x,y,step]=q.top();q.pop();
		if(vis[{x,y}])continue;
		vis[{x,y}]=1;
		if(x==tx&&y==ty){
			cout<<step<<endl;
			return ;
		}
		int j;
		for(int i=0;i<4;i++){
			if(v[y][i]==x){
				j=(i+1)%4;
				break;
			}
		}
		for(int i=0;i<4;i++){
			if(i==j)q.push({y,v[y][i],step});
			else q.push({y,v[y][i],step+1});
		}
	}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}