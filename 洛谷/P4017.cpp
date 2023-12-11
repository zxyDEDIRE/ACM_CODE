#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int mod=80112002;
const int maxn=1e6;
vector<int>v[maxn];
int dis[maxn];
int in[maxn];
int n,m;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		in[y]++;
	}
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(!in[i]){
			dis[i]=1;
			q.push(i);
		}
	ll ans=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		if(v[x].size()==0)ans=(ans+dis[x])%mod;
		for(int i=0;i<v[x].size();i++){
			int y=v[x][i];
			dis[y]+=dis[x];
			dis[y]%=mod;
			in[y]--;
			if(!in[y])q.push(y);
		}
	}
	cout<<ans<<endl;
}