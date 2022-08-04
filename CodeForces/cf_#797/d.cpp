#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
string str;
int p[maxn];
int n,k;
void solve()
{
	cin>>n>>k>>str;
	for(int i=0;i<n;i++)
		p[i+1]=p[i]+(str[i]=='B'?1:0);
	int mi=n;
	for(int i=1;i+k-1<=n;i++)
		mi=min(mi,k-p[i+k-1]+p[i-1]);
	cout<<mi<<endl;
}
int main()
{
	int __;cin>>__;
	while(__--)solve();
}