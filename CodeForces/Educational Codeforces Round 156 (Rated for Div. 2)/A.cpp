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
void NO(){cout<<"NO\n";}
void solve()
{
	int n;
	cin>>n;
	if(n%3==0)
	{
		if(n<12)return NO();
		cout<<"YES\n";
		cout<<1<<" "<<4<<" "<<n-5<<endl;
	}
	else if(n%3==1)
	{
		if(n<7)return NO();
		cout<<"YES\n";
		cout<<1<<" "<<2<<" "<<n-3<<endl;
	}
	else
	{
		if(n<8)return NO();
		cout<<"YES\n";
		cout<<1<<" "<<2<<" "<<n-3<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
1:
1 1 2
0 3 0
1 4 2

2:
2 1 2
0 0 3
2 1 5

0:
1 1 1
0 3 6
1 4 7

1 1 1
0 3 6
1 4 7


*/