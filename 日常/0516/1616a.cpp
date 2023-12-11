#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
int n,x;
void solve()
{
	cin>>n;
	int ans=0;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(!mp[x])mp[x]=1,ans++;
		else if(!mp[-x])mp[-x]=1,ans++;
	}
	cout<<ans<<endl;
}
int main(){
  int __;
  cin>>__;
//  __=1;
  while(__--)solve();
  return 0;
}
/*
0
1
10
11
100
101
110
111
*/