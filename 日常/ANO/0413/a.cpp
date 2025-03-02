#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4;
int main()
{
	int n1,n2,n,m1=0,m2=0;
	cin>>n1>>n2>>n;
	for(int i=1;i<=n;i++)
	{
		int a,aa,b,bb,f1=0,f2=0;
		cin>>a>>aa>>b>>bb;
		if(aa==a+b)f1++;
		if(bb==a+b)f2++;
		if(f1!=0&&f2==0)m1++;
		if(f1==0&&f2!=0)m2++;
	//	cout<<"fl:"<<f1<<" "<<f2<<endl;
	//	cout<<"ans:"<<m1<<" "<<m2<<endl;
		if(m1>n1)
		{
			cout<<"A"<<endl;
			cout<<m2<<endl;
			break;
		}
		if(m2>n2)
		{
			cout<<"B"<<endl;
			cout<<m1<<endl;
		}
	}
}