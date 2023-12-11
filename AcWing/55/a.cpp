#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cout.tie(0);cout.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
bitset<maxn>vis;
int p[maxn];
int n,m;
int main()
{	ios
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=m;i++){
		int x;cin>>x;
		vis[x]=1;
	}
	for(int i=1;i<=n;i++)
		if(vis[p[i]])cout<<p[i]<<" ";
	
	
}