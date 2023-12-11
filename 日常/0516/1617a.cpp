#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
string s,t;
void solve()
{
	cin>>s>>t;
	sort(s.begin(),s.end());
	if(t=="abc")
	{
		int a=0,b=0,c=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='a')a++;
			else if(s[i]=='b')b++;
			else if(s[i]=='c')c++;
		}
		if(a&&b&&c)
		{
			for(int i=0;i<a;i++)cout<<"a";
		for(int i=0;i<c;i++)cout<<'c';
		for(int i=0;i<b;i++)cout<<'b';
		for(int i=a+b+c;i<s.size();i++)cout<<s[i];
			cout<<endl;
		}
		else cout<<s<<endl;
		
	}
	else cout<<s<<endl;
}
int main(){
	int __;cin>>__;
	while(__--)solve();
}
/*
abc
*/