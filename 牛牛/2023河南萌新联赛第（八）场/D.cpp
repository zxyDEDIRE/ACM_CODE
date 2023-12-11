#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
const int N=1111;
string str;
int x,y,n;
int lenx,leny;
bool check(int a,int b)
{
	int lx=x-a;
	int ly=y-b;
	if(lx==0&&ly==0)return 1;
	int fa=0,fb=0;
	if(lx==0&&lenx==0)fa=1;
	else if(lenx!=0&&lx%lenx==0&&(lx/lenx)<n&&(lx/lenx)>0)fa=1;

	if(ly==0&&leny==0)fb=1;
	else if(leny!=0&&ly%leny==0&&(ly/leny)<n&&(ly/leny)>0)fb=1;
	
	if(fa&&fb)return 1;
	return 0;
}
void solve()
{
	cin>>x>>y>>n>>str;
	if(x==0&&y==0){
		cout<<"Yes"<<endl;
		return ;
	}
	lenx=0,leny=0;
	for(auto i:str)
	{
		if(i=='U')leny++;
		else if(i=='D')leny--;
		else if(i=='L')lenx--;
		else lenx++;
	}
	int tx=0,ty=0;
	for(auto i:str)
	{
		if(i=='U')ty++;
		else if(i=='D')ty--;
		else if(i=='L')tx--;
		else tx++;

		if(check(tx,ty)){
			cout<<"Yes"<<endl;
			return ;
		}
	}
	cout<<"No"<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
1
-100 100
99
UL
*/