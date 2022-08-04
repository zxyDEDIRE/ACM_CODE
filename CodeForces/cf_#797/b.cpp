#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int a[maxn],b[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	int x=0x3f3f3f3f,y=0;
	for(int i=1;i<=n;i++)
	{
		y=max(y,a[i]-b[i]);
		if(b[i]!=0)x=min(x,a[i]-b[i]);
	}
	if(y<=x)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
int main()
{
	int __;cin>>__;
	while(__--)solve();
}