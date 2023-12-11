/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
vector<int>v;
bitset<100>vis;
set<int>s;
int n,m;
void f(int x)
{
	vector<int>a;
	while(x)
	{
		a.push_back(x%2);
		x/=2;
	}
	for(int i=0;i<a.size();i++)
		if(a[i]==1)
			v.push_back(i);
	m=v.size();
}
void dfs(int x,int num)
{
	if(x==m)
	{
		s.insert(num);
		return ;
	}
	for(int i=x;i<m;i++)
	{
		dfs(i+1,num+(1ll<<(v[i])));
		dfs(i+1,num);
	}
}
void solve()
{
	cin>>n;
	f(n);
	dfs(0,0);
	for(auto i:s)
		cout<<i<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}