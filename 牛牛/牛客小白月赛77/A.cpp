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
int mp[9][9];
bool check()
{
	set<int>s;
	for(int i=1;i<=2;i++)
	{
		int a=0,b=0;
		for(int j=1;j<=2;j++)
		{
			a+=mp[i][j];
			b+=mp[j][i];
		}
		s.insert(a);
		s.insert(b);
	}
	return (int)s.size()==1;
}
void solve()
{
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
			cin>>mp[i][j];
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++){
			int old=mp[i][j];
			for(int k=0;k<=9;k++){
				mp[i][j]=k;
				if(check()){cout<<"YES\n";return ;}
			}
			mp[i][j]=old;
		}
	cout<<"NO"<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}