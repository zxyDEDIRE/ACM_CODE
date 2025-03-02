#include<bits/stdc++.h>
#define int long long
using namespace std;
char p[]={"ABC"};
string str;
int T,t,k;
void doit()
{
	int x=0,y;
	int q=0;
	cout<<"*";
	for(int i=1;i<=t;i++)
	{
		y=(k+1)/2;
		if(y*2==k)q=(q-1+3)%3;
		else q=(q+1)%3;
		k=(k+1)/2;
	}
	cout<<"*";
	if(str[k]=='A')y=0;
	else if(str[k]=='B')y=1;
	else y=2;
//	cout<<k<<" "<<q<<endl;
	cout<<p[(y+q)%3]<<endl;
}
signed main()
{
	cin>>str;
	cin>>T;
	str=" "+str;
	while(T--)
	{
		cin>>t>>k;
		doit();
	}
}
/*
abc
bc ca ab
ca ab ab bc bc ca
*/
