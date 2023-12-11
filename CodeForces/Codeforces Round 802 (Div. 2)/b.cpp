#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
string str;
int n;
void solve()
{
	cin>>n>>str;
	if(str[0]=='9')
	{
		int ans=1;
		string t="";
		for(int i=0;i<=n;i++)
			t+='1';
		reverse(str.begin(),str.end());
		vector<int>v;
		for(int i=0;i<n;i++)
		{
			int x=str[i]-'0';
			int y=t[i]-'0';
			if(y<x)t[i+1]--,y=y+10;
			v.push_back(y-x);
		}
		for(int i=v.size()-1;i>=0;i--)
			cout<<v[i];
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			int x=str[i]-'0';
			cout<<9-x;
		}
	}
	cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}
/*
111
 99
*/