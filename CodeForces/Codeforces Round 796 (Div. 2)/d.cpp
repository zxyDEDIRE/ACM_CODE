#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll sum[maxn];
ll p[maxn];
ll n,k;
void solve()
{
	cin>>n>>k;
	ll q=0,ans=0;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		q+=p[i];
		if(i<=k)ans+=i-1;
		sum[i]=p[i]+sum[i-1];
	}
	if(k>=n)
	{
		k-=n;q+=ans;
		cout<<q<<endl;
		q+=k*n;
		
		cout<<q<<endl;
		return ;
	}
	ll ma=0;
	for(int i=1;(i+k-1)<=n;i++){
		ma=max(ma,sum[i+k-1]-sum[i-1]);
	}
	cout<<ma+ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;
    cin>>__;
//    __=1;
    while(__--)solve();
    return 0;
}
/*
4 7
1 1 1 1
1 2 2 2
2 1 3 3
3 2 1 4
4 3 2 1
10
-------
5 4 1 2
6 1 2 3
1 2 3 4
2+4+6
22

4 5
1 1 1 1
2 1 2 2
1 2 3 3
2 1 4 4
3 2 1 5
4 3 2 1
*/