#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
map<ll,ll>mp;
ll n,x;
int f(ll y){
	int ans=0;
	while(y)y/=10,ans++;
	return ans;
}
int dfs(ll x,int p){
	
}
void solve()
{
	cin>>n>>x;
	cout<<dfs(n)<<endl;
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
*/