#include<bits/stdc++.h>
#define lom long long
using namespace std;
 
lom quick(lom a,lom b,lom c)//快速幂取模 
{
	lom ans=1;
	a%=c;
	while(b)
	{
		if(b&1) ans=ans*a%c;
		a=a*a%c;	
		b>>=1;
	}
	return ans%c;
}
 
lom divi(lom a,lom b,lom p)
{
	b=quick(b,p-2,p); //b的逆元 
	
	return a*b%p; 
}
int main()
{
	lom n,p,q;
	while(cin>>q>>n>>p)
	{
		lom t=1*(quick(q,n,p)-1);
		cout<<divi(t,q-1,p)<<endl;
		break;
	}
	return 0;
}