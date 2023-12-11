#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn];
int n,m;
void solve()
{
	cin>>n;
	bitset<maxn>vis;
	ll sum=0;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		vis[p[i]]=1;
		sum+=p[i];
	}
	if(sum%n==0&&vis[sum/n])cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
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