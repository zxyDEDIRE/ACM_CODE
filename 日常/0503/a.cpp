#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
bitset<maxn>vis;
int a[maxn],b[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(a[i]>b[i])swap(a[i],b[i]);
	}
	long long ans=0;
	for(int i=1;i<n;i++)
		ans+=abs(a[i+1]-a[i])+abs(b[i+1]-b[i]);
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)solve();
}