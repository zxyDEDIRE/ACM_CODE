#include<bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'
int h, c;
void solve()
{
	if(c<h)cout<<h<<endl;
	else{
		cout<<c+1<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	while(cin >> h >> c){
		solve();
	}
	return 0;

}