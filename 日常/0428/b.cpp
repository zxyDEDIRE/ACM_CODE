#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
int p[10];
int main()
{
	int __;
	cin>>__;
	while(__--)
	{
		int a,b,c;
		cin>>a>>b;
		c=b*2;
		while(1)
		{
			if(__gcd(c,a)==b){
				cout<<c<<endl;
				break;
			}
			c+=a;
		}
	}
}