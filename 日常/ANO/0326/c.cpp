#include<bits/stdc++.h>
using namespace std;
using int64 = long long;
const int maxn=1e6;
int p[maxn];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		printf("%2d ",n%i);
	cout<<endl;
	for(int i=1;i<=n;i++)printf("%2d ",i);
}
