#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
vector<int>v[maxn];
int p[maxn];
int x,y,k,n;
void solve()
{
	cin>>n>>k>>x>>y;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
}
int main(){
	int __;cin>>__;
	while(__--)solve();
}