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
const int maxn=1e6;
struct node{
	int x,l,r;
}p[maxn];
string str;
int n;
void solve()
{
	cin>>n>>str;
	deque<int>q;
	q.push_front(n);
	for(int i=n-1;i>=0;i--)
	{
		if(str[i]=='L')q.push_back(i);
		else q.push_front(i);
	}
	while(!q.empty())
	{
		int x=q.front();q.pop_front();
		cout<<x<<" ";
	}
	cout<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

        solve();
    return 0;
}