#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
ll n;
__int128 s(__int128 x)
{
	__int128 l=1,r=x/2;
	// cout<<"A\n";
	while(l<r-1)
	{
		// cout<<"S";
		__int128 mid=(l+r)/2;
		if(mid*mid==x)return mid;
		else if(mid*mid<x)l=mid+1;
		else r=mid-1;
	}
	while(l*l<x)l++;
	while(l*l>x)l--; 
	return l;
}
void solve(int n)
{
	// cout<<n<<" ";
	__int128 a=1;
	__int128 ans=a*n*(n+1)*(2*n+1)/6;
	__int128 x=s(ans);

	if(x*x==ans){
		cout<<"find "<<n<<endl;
	}

	// if(x*x==ans)cout<<"Fake news!\n";
	// else cout<<"Nobody knows it better than me!\n";
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	for(int i=1;i<=1000000000;i++)
		solve(i);
	return 0;
}
/*
1000000000000000
*/