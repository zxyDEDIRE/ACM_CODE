#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define int long long
#define endl '\n'
typedef long long ll;
typedef pair<int,int> P;
const int N=1e6+7;
const int INF=0x3f3f3f3f3f3f3f3f;
const int mod=998244353;
void solve()
{
	int n,x;
	cin>>n>>x;
	int fl=0;
	int xx=n;
	for(int i=0;i<=61;i++){
		int a=((n&(1ll<<i))!=0);
		int b=((x&(1ll<<i))!=0);
		// cout<<"i="<<i<<" "<<a<<" "<<b<<endl;
		if(a==0&&b==1){
			cout<<-1<<endl;
			// cout<<"***"<<endl;
			return;
		}
		if(a==1&&b==0)fl=1;
		if(a==0&&fl){
			int t=(1ll<<61)-1;
			t^=(1ll<<i)-1;
			xx&=t;
			fl=0;
			n&=t;
			n|=(1ll<<i);
			// cout<<"dd "<<i<<endl;
		}
	}
	cout<<"YES"<<endl;
	// cout<<"end"<<endl;
	// cout<<x<<" "<<xx<<endl;
	if(xx==x)cout<<n<<endl;
	else cout<<-1<<endl;
}
signed main()
{
	IOS
	int __=1;
	cin >> __;
	while (__--)
		solve();
}
/*
8421
1110
1010

14
10
*/