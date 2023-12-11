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
vector<int>a,b,c;
int n,l,r;
void solve()
{
	cin>>n>>l>>r;
	a.clear();
	b.clear();
	c.clear();
	vector<int>in(n+2),out(n+2);
	for(int i=1;i<=l;i++)
	{
		int x;cin>>x;
		c.push_back(x);
		in[x]++;
	}
	for(int i=1;i<=r;i++)
	{
		int x;cin>>x;
		if(in[x]>0)
		{
			out[x]++;
			in[x]--;
		}
		else b.push_back(x);
		
	}

	for(int i=0;i<c.size();i++)
	{
		if(out[c[i]]>0)out[c[i]]--;
		else a.push_back(c[i]);
	}

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	
	int ans=0,len=min(a.size(),b.size());
	for(int i=0;i<len;i++)
	{
		if(a[i]!=b[i])ans++;
	}
	if(a.size()>len)
	{
		for(int i=len;i<a.size()-1;i+=2)
		{
			if(a[i]==a[i+1])ans+=1;
			else ans+=2;
		}
	}
	else if(b.size()>len)
	{
		for(int i=len;i<b.size()-1;i+=2)
		{
			if(b[i]==b[i+1])ans+=1;
			else ans+=2;
		}
	}
	cout<<ans<<endl;

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