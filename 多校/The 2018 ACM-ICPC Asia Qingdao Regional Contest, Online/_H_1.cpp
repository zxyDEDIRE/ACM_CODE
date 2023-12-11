#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=1e5;

string s,t;
int n;
void solve()
{
	cin>>s>>t;
	n=s.size();
	string str=string(n,'a');
	vector<int>a,b;
	for(int i=0;i<n;i++)
	{
		int fa=(str[i]==s[i]);
		int fb=(str[i]==t[i]);
		if(fa&&!fb)a.push_back(i);
		if(!fa&&fb)b.push_back(i);
	}
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]==str[i])continue;
		if(t[i]==str[i])continue;
		if(a.size()<b.size())a.push_back(i);
		if(b.size()<a.size())b.push_back(i);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(auto i:a)
		str[i]=s[i];
	for(auto i:b)
		str[i]=t[i];	
	int len=a.size();
	
	auto nt=[&](char a,char b)->char{
		char x='a';
		while(x==a||x==b)
			x++;
		return x;
	};

	for(int i=0;i<len;i++)
	{
		int x=a[i];
		int y=b[i];
		char _s = nt(s[x],t[x]);
		char _t = nt(s[y],t[y]);
		if(x<y && _s<s[x])
		{
			str[x]=_s;
			str[y]=_t;
		}
		else if(y<x && _t<t[y])
		{
			str[x]=_s;
			str[y]=_t;
		}	
	}
	cout<<str<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	for(int i=1;i<=T;i++){
		cout<<"Case "<<i<<": ";
		solve();
	}
	return 0;
}
/*
abandon
newyork
*/