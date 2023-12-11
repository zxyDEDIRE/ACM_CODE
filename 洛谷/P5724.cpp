#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int main()
{
	int ma,mi,n,x;
	cin>>n;
	cin>>ma,mi=ma;
	for(int i=1;i<n;i++)
	{
		cin>>x;
		ma=max(ma,x);
		mi=min(mi,x);
	}
	cout<<ma-mi<<endl;
}