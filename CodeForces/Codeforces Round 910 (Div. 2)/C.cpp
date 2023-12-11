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
int n,m,k;
void solve()
{
	cin>>n>>m>>k;
	int t=n+m-2;
	if(k<t||(k-t)%2!=0){
		cout<<"NO\n";
		return ;
	}
	// cout<<t<<endl;
	// cout<<(k-t)%4<<endl;
	cout<<"YES\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(i==2&&j==1)cout<<"B ";
			else if(j&1)cout<<"R ";
			else cout<<"B ";
		}
		cout<<endl;
	}
	// cout<<endl;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==1&&j<=2)cout<<"R ";
			else if(m&1)
			{
				if(i&1)cout<<"R ";
				else cout<<"B ";
			}
			else
			{
				if(i&1)cout<<"B ";
				else cout<<"R ";
			}
		}
		cout<<endl;
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

*/