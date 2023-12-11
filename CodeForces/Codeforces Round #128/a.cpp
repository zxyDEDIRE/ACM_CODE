#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e3;
int p[maxn];
map<ll,bool>mp;
int n,w;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>w;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	ll ans=0;
	for(int i=1;i<=n;i++)
		if(!mp[p[i]]&&p[i]<=w)ans++,mp[p[i]]=1;
//	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int t=p[i]+p[j];
			if(!mp[t]&&t<=w)ans++,mp[t]=1;//,cout<<t<<endl;;
		}
	}
//	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				int t=p[i]+p[j]+p[k];
				if(!mp[t]&&t<=w)ans++,mp[t]=1;
			}
		}
	}
	cout<<ans<<endl;
}