#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
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
map<int,bool>f[2];
int n;
bool sg(int x,int t){
	if(x==1) return 0;
	if(f[t].count(x)) return f[t][x];
	int ff=0;
	for(int i=1;1ll*i*i<=x;i++){
		if(x%i==0){
			if(i!=1){
				int d=i;
				int val=0;
				if(d%4==2){
					val=sg(x/i,t)^sg(x/i,t^1)^1;
				}
				else if(d%4==1){
					val=sg(x/i,t^1);
				}else if(d%4==3){
					val=sg(x/i,t)^1;
				}
				if(val==1){
					ff=1;break;
				}
			}
			if(x/i!=1){
				int d=x/i;
				int val=0;
				if(d%4==2){
					val=sg(i,t)^sg(i,t^1)^1;
				}
				else if(d%4==1){
					val=sg(i,t^1);
				}else if(d%4==3){
					val=sg(i,t)^1;
				}
				if(val==1){
					ff=1;break;
				}
			}
		}
	}
	return f[t][x]=ff;
}
/*
1
3
3 5 4
*/
void solve()
{
	f[0].clear();f[1].clear();
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		ans^=sg(x,0);
	}
	if(!ans){
		cout<<"L\n";
	}else{
		cout<<"W\n";
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	srand(time(0));
	int __;
	cin>>__;
	while(__--)
		solve();
	return 0;
}
/*

*/