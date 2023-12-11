#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
string str;
int n,m;
void solve()
{
	cin>>n>>m;
	if((n==1&&m>2)||(n>2&&m==1)){
		cout<<-1<<endl;
		return ;
	}
	int ans=n+m-2;
	if(n<m)swap(n,m);
	if(n-1>m)ans+=(n-1-m);
	cout<<ans<<endl;
}
int main(){
	int __;cin>>__;
	while(__--)solve();
}