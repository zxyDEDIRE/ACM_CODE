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
int n,a,b;
void solve()
{
	cin>>n>>a>>b;
	vector<int>x,y;
	if(a<b)
	{
		for(int i=1;i<a;i++)
			y.push_back(i);
		for(int i=b+1;i<=n;i++)
			x.push_back(i);
		x.push_back(a);
		y.push_back(b);
		if(x.size()>n/2||y.size()>n/2){
			cout<<-1<<endl;
			return ;
		}
		for(int i=a+1;i<b;i++)
		{
			if(x.size()<n/2)x.push_back(i);
			else if(y.size()<n/2)y.push_back(i);
		}
		for(auto i:x)
			cout<<i<<" ";
		for(auto i:y)
			cout<<i<<" ";
		cout<<endl;
	}
	else
	{
		for(int i=1;i<a;i++)
			y.push_back(i);
		for(int i=b+1;i<=n;i++)
			x.push_back(i);
		if(x.size()>n/2||y.size()>n/2){
			cout<<-1<<endl;
			return ;
		}
		for(auto i:x)
			cout<<i<<" ";
		for(auto i:y)
			cout<<i<<" ";
		cout<<endl;
	}
}
//min=a max=b
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}