#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
void solve()
{
	ll n,ans=0,b=0,w=0;
	cin>>n;
	vector<pair<ll,bool> >v;
	for(int i=1;i<=n;i++){
		ll x;char ch;
		cin>>x>>ch;
		if(ch=='B')v.push_back(pair<ll,bool>(x,0)),b+=x;
		else v.push_back(pair<ll,bool>(x,1)),w+=x;
	}
	if(b==0||w==0){
		cout<<b+w<<"\n";
		return ;
	}
	ll bb=0,ww=0,i=0;
	while(i<n)
	{ 
		ll BB=bb,WW=ww;
		if(v[i].second=='0')bb+=v[i].first;
		else (v[i].second=='1')ww+=v[i].first;

		if(ww*b==bb*w)ans++;
		else if(WW*b<BB*w&&ww*b>bb*w)ans++;
		else if(WW*b>BB*w&&ww*b<bb*w)ans++;
		i++;
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)solve();
}
/*
a aa
b bb
w ww
*/