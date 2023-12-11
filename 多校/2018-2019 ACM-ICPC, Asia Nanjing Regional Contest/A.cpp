#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a,b;
	cin>>a>>b;
	if(a==0)cout<<"Austin"<<endl;
	else if(a&1)cout<<"Adrien"<<endl;
	else if((a%2==0)&&b>=2)cout<<"Adrien"<<endl;
	else cout<<"Austin"<<endl;
	return 0;
}