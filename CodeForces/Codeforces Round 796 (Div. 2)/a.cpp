#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
void solve()
{
	ll x;
	cin>>x;
	ll ans=0;
	ll cnt=0;
	for(int i=0;i<=30;i++){
		if((x>>i)&1){
			cnt++;
			if(cnt==1)
				ans|=(1<<i);
		}
	}
	if(cnt>1)cout<<ans<<endl;
	else {
		if(ans>1)cout<<ans+1<<endl;
		else cout<<ans+2<<endl;
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
/*
1
11

01
11

*/