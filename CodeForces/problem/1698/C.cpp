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
void solve()
{
	map<int,bool>mp;
	vector<int>v;
	int n,a=0,b=0,c=0;

	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		if(x<0)a++,v.push_back(x);
		else if(x>0)b++,v.push_back(x);
		else if(c<=2)c++,v.push_back(x);
		mp[x]=1;
	}
	if(a>2||b>2){
		cout<<"No"<<endl;
		return ;
	}
	n=v.size();
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				//cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<endl;
				if(!mp[v[i]+v[j]+v[k]]){
					cout<<"No"<<endl;
					return ;
				}
			}
		}
	}
	cout<<"Yes"<<endl;
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