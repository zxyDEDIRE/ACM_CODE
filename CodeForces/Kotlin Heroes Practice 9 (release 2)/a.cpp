#include<bits/stdc++.h>

using namespace std;



int main()
{
	int T;cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int a=0,b=0,cnta=0,cntb=0,fa=0,fb=0;
		for(int i=1;i<=n;i++)
		{
			int x;cin>>x;
			if(x==a)cnta++;
			else if(x==b)cntb++;
			else if(a==0)
			{
				a=x;
				fa=i;
				cnta++;
			}
			else if(b==0)
			{
				b=x;
				fb=i;
				cntb++;
			}

		}
	}
}