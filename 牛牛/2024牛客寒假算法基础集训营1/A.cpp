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
void solve()
{
	string str;
	int n;
	cin>>n;
	cin>>str;
	int fa=0,fb=0;
	for(auto i:str)
	{
		if(fa==0&&i=='D')fa++;
		else if(fa==1&&i=='F')fa++;
		else if(fa==2&&i=='S')fa++;

		if(fb==0&&i=='d')fb++;
		else if(fb==1&&i=='f')fb++;
		else if(fb==2&&i=='s')fb++;
	}
	cout<<(fa==3)<<" "<<(fb==3)<<endl;
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