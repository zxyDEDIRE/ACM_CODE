#include<bits/stdc++.h>
using namespace std;
string s;
int l,r,x;
int f(int y)
{
	string a=to_string(y);
	if(a.find(s)!=string::npos)
		return 1;
	return 0;
}
int main()
{
	cin>>l>>r>>x;
	s=to_string(x);
	int cnt=0;
	for(int i=l;i<=r;i++)
		cnt+=f(i);
	cout<<cnt<<endl;
	return 0;
}