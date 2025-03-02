#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int l,r,a;
void solve()
{
	cin>>l>>r>>a;
	for(int i=l;i<=r;i++)
	cout<<(i/a+i%a)<<" ";
}
signed main(){
	int __;cin>>__;
	while(__--)solve();
}
