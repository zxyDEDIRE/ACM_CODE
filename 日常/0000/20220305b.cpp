#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=1e6;
string a;
int n;
void doit()
{
	string s;
	for(int i=0;i<a.size();i++)
		if(a[i]=='A')s=s+"BC";
		else if(a[i]=='B')s=s+"CA";
		else s=s+"AB";
	cout<<s<<endl;
	a=s;
}
signed main()
{
	cin>>a>>n;
	for(int i=1;i<=n;i++)doit();
}
