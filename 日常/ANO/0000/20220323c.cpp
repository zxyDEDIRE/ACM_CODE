#include<bits/stdc++.h>
using namespace std;
using int64 = long long;
int main()
{
	int a;
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=i;j++)
			cout<<"*";
		cout<<endl;
	}
}