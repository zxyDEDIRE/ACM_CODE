#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int main()
{
	int n;
	cin>>n;
	for(int x=100;x>=1;x--)
	{
		for(int k=1;k<=1000;k++)
		{
			if(364*x+1092*k==n){
				cout<<x<<endl<<k<<endl;
				return 0;
			}
		}
	}
}
/*
52

7*52*x
(1+6)*6/2*52

364x
1092
7*3*52k
7*156k
392k
*/