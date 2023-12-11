#include<bits/stdc++.h>
using namespace std;
set<string>s;
int n;
int cnt=0;
void dfs(int step,string now)
{
	if(step==n)
	{
		int num=0;
		int l=0,r=n-1;
		while(l<=r)
		{
			if(now[l]!=now[r])num++; 
			l++,r--;
		}
		if(num==1)
			s.insert(now);
		return ;
	}
	for(int i=1;i<=26;i++)
	{
		string s=now+(char)(i+'a'-1);
		dfs(step+1,s);
	}
}
void solve()
{
	cin>>n;
	dfs(0,"");
	cout<<s.size()<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}