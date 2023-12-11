#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
ll n,k;
void solve()
{
	cin>>n>>k;
	ll ans=(((0+n-1)*n/2)-(n/2))/2;
	if(k>ans){cout<<-1<<endl;return ;
	}
	if(k>=ans/2)
	{
		ll flag=ans-k+1;
		for(int i=0;i<n;i++){
			if(i==flag)cout<<1<<" ";
			else if(i==1)cout<<flag<<" ";
			else cout<<i<<" ";
			if(i&1)cout<<"\n";
		}
	}
	else
	{

	}
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;
	cin>>__;
//    __=1;
	while(__--)solve();
	return 0;
}