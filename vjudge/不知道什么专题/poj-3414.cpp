/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct node{
	vector<int>p;
	int step;
	vector<int>v;
};
bool vis[111][111];
int w[2],t;
void bfs()
{
	queue<node>q;
	node S;
	S.p.push_back(0);
	S.p.push_back(0);
	S.step=0;
	q.push(S);
	vis[0][0]=1;
	while(!q.empty())
	{
		node x=q.front();q.pop();
		vector<int>p=x.p;
		vector<int>v=x.v;

		if(p[0]==t||p[1]==t){
			cout<<v.size()<<endl;
			for(int j=0;j<v.size();j++)
			{
				int i=v[j];
				if(i==1)cout<<"DROP(1)"<<endl;
				else if(i==2)cout<<"FILL(1)"<<endl;
				else if(i==3)cout<<"DROP(2)"<<endl;
				else if(i==4)cout<<"FILL(2)"<<endl;
				else if(i==5)cout<<"POUR(1,2)"<<endl;
				else cout<<"POUR(2,1)"<<endl;
			}
			return ;
		}
		if(!vis[0][p[1]]){
			vis[0][p[1]]=1;
			node now=x;
			now.p[0]=0;
			now.step++;
			now.v.push_back(1);
			q.push(now);
		}
		if(!vis[w[0]][p[1]]){
			vis[w[0]][p[1]]=1;
			node now=x;
			now.p[0]=w[0];
			now.step++;
			now.v.push_back(2);
			q.push(now);
		}
		if(!vis[p[0]][0]){
			vis[p[0]][0]=1;
			node now=x;
			now.p[1]=0;
			now.step++;
			now.v.push_back(3);
			q.push(now);
		}
		if(!vis[p[0]][w[1]]){
			vis[p[0]][w[1]]=1;
			node now=x;
			now.p[1]=w[1];
			now.step++;
			now.v.push_back(4);
			q.push(now);
		}
		if(!vis[p[0]-min(p[0],w[1]-p[1])][p[1]+min(p[0],w[1]-p[1])])
		{
			vis[p[0]-min(p[0],w[1]-p[1])][p[1]+min(p[0],w[1]-p[1])]=1;
			node now=x;
			now.p[0]=p[0]-min(p[0],w[1]-p[1]);
			now.p[1]=p[1]+min(p[0],w[1]-p[1]);
			now.step++;
			now.v.push_back(5);
			q.push(now);
		}
		if(!vis[p[0]+min(p[1],w[0]-p[0])][p[1]-min(p[1],w[0]-p[0])])
		{
			vis[p[0]+min(p[1],w[0]-p[0])][p[1]-min(p[1],w[0]-p[0])]=1;
			node now=x;
			now.p[0]=p[0]+min(p[1],w[0]-p[0]);
			now.p[1]=p[1]-min(p[1],w[0]-p[0]);
			now.step++;
			now.v.push_back(6);
			q.push(now);
		}
	}
	cout<<"impossible"<<endl;
}
void solve()
{
	cin>>w[0]>>w[1]>>t;
	bfs();
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
        solve();
    return 0;
}