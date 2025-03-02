#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,k;
void solve()
{
	cin>>n>>m>>k;
	int s=1,t=1;
	for(int i=1;i<=k;i++)s*=(n-m);
	for(int i=1;i<=k;i++)t*=n;
	cout<<s*n<<" "<<t<<endl;
}
signed main(){
	int __;cin>>__;
	while(__--)solve();
}