#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
int main()
{
	vector<int>p(200);
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=100;j++)
		{
			if(j%i==0)p[j]^=1;
		}
	}
	for(int i=1;i<=100;i++)cout<<p[i]<<" ";
}