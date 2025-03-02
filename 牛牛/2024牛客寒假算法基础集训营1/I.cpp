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
pp(3) p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++)
			cin>>p[i][j];
	int fa=0,fb=0;
	for(int i=1;i<=n;i++)
	{
		if(abs(p[i][0])>=50)fa++;
		if(abs(p[i][1])>=50)fb++;
	}
	double _x,_y;
	_x=1.0*fa/n;
	_y=1.0*fb/n;
	if(_x<0.5&&_y<0.5)cout<<"buaa-noob\n";
	else cout<<"bit-noob\n";

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}