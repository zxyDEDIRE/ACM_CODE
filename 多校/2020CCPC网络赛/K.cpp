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
int n;
const int N=55;
int mp[N][N];
int a[3][3];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>mp[i][j];
		}
	}
	int f=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			int x;
			cin>>x;
			if(x&&i==0&&j==0) f=1;
			else if(x) f=0;
		}
	}
	if(f==1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<mp[i][j]<<" ";
			}cout<<'\n';
		}
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<0<<" ";
			}cout<<'\n';
		}
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