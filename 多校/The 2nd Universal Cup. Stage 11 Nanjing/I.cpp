#include<bits/stdc++.h>
using namespace std;
#define endl '\n';
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6+10;
const int mod=1e9+7;


pii p[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		auto &[x,y]=p[i];
		cin>>x>>y;
	}
	sort(p+1,p+1+m);
	int _x=0,_y=0;
	for(int i=1;i<=m;i++)
	{
		auto [x,y]=p[i];
		int ned=y+1;

		if(x-_x==y-_y)ned=y-_y;
		
		if(x-_x<ned){
			cout<<"No\n";
			return;
		}

		_x=x;
		_y=y;
	}
	cout<<"Yes\n";

}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*





3
7 4
2 2
4 0
5 1
7 1

3 2
2 2
3 1

3 1
3 100
*/