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
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	vector<int>x,y;
	x.push_back(p[1]);
	for(int i=2;i<=n;i++)
	{
		if(p[i]==p[i-1])y.push_back(p[i]);
		else x.push_back(p[i]);
	}
	// cout<<"*"<<endl;
	// for(auto i:x)cout<<i<<" ";cout<<endl;
	// 	for(auto i:y)cout<<i<<" ";cout<<endl;
	int num=0;
	if(x.size())
	{
		num++;
		for(int i=1;i<x.size();i++)
		{
			if(x[i]!=x[i-1])num++;
		}
	}

	if(y.size())
	{
		num++;
		for(int i=1;i<y.size();i++)
		{
			if(y[i]!=y[i-1])num++;
		}
	}

	cout<<num<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
	return 0;
}