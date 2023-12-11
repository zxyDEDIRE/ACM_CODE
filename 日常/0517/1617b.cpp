#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
void solve()
{
	int n;
	cin>>n;
	if(!(n&1))cout<<n/2<<" "<<n/2-1<<" "<<1<<endl;
	else
	{
		if(n%3==0)cout<<n/3-1<<" "<<n/3<<" "<<n/3+1<<endl;
		else if(n%3==2)cout<<n/3<<" "<<n/3+1<<" "<<n/3+1<<endl;
		else cout<<(n-3)/2<<" "<<3<<" "<<(n-3)/2<<endl;
	}
}
int main(){
//	cout<<__gcd(12,1)<<endl;
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int __;
    cin>>__;
//    __=1;
    while(__--)solve();
    return 0;
}
/*
21
7 8 8

*/