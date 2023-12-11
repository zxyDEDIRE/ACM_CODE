/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define endl "\n"
const int maxn=1e6;
unsigned long long bfs(int n)
{
	queue<unsigned long long>q;
	q.push(1);
	while(!q.empty())
	{
		unsigned long long x=q.front();q.pop();
		if(x%n==0)return x;
		q.push(x*10);
		q.push(x*10+1);
	}
	return -1;
}
void solve()
{
	int n;
	while(cin>>n)
	{
		if(n==0)break;
		cout<<bfs(n)<<endl;
	}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}