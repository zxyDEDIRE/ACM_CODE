#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;

const int maxn=1e6+100;
ll v[110];
int n;

bool check(){
	bool flag = 0;
	for(int i = 31; i > 0; i --){
		while(v[i] > v[i-1]){
			flag = 1;
			v[i] --;
			v[i-1] += 2;
		}
	}
	return flag;
}
void solve()
{
	cin>>n;
	memset(v,0,sizeof(v));
	for(int i=1;i<=n;i++)
	{
		ll x;
		cin>>x;
		for(int j=0;j<32;j++)
			if(x&(1ll<<j))
				v[j]++;
	}
	
	while(check());
	
	ll ma=0;
	for(int i=0;i<32;i++){
		ma=max(ma,v[i]);
		// cout<<v[i]<<" ";
	}
	// cout<<endl;
	cout<<ma<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}