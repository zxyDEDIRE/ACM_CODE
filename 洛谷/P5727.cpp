#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn],cnt;
int main()
{
	int n;
	cin>>n;

	while(n!=1)
	{
		p[++cnt]=n;
		if(n&1)n=n*3+1;
		else n/=2;
	} 
	p[++cnt]=1;
	for(int i=cnt;i>=1;i--)
		cout<<p[i]<<" ";
}
