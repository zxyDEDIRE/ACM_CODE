#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cout.tie(0);cout.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
string s,t;
int n;
void solve()
{
	cin>>n>>s>>t;
	vector<int>a,aa,c,cc,b,bb;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='a')a.push_back(i);
		else if(s[i]=='c')c.push_back(i);

		if(t[i]=='a')aa.push_back(i);
		else if(t[i]=='c')cc.push_back(i);

		if(s[i]!='b')b.push_back(s[i]-'a');
		if(t[i]!='b')bb.push_back(t[i]-'a');
	}
	if(b!=bb){cout<<"NO\n";return ;}
	for(int i=0;i<a.size();i++)
	{
		if(aa[i]<a[i]){cout<<"NO\n";return ;}
	}
	for(int i=0;i<c.size();i++)
	{
		if(cc[i]>c[i]){cout<<"NO\n";return ;}
	}
	cout<<"Yes\n";
	丨;
}
int main()
{	ios

	int __;cin>>__;
	while(__--)
		solve();
	
}