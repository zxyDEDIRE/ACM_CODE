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
bool vis[maxn];
int a[maxn];
int n;
bool check()
{
	multiset<int>s;
	for(int i=1;i<=n;i++)
		s.insert(a[i]);
	int cnt=0;
	while(1)
	{
		int x=*s.begin();//mi
		int y=*s.rbegin();//ma
		// cout<<x<<" "<<y<<endl;
		if(x==y){
			cout<<cnt<<endl;
			return 1;
		}
		cnt++;
		if((x<<1)>(y>>1))return 0;
		s.erase(s.find(x));
		s.erase(s.find(y));
		s.insert(x<<1);
		s.insert(y>>1);
	}
	return 0;
}
void solve()
{
	cin>>n;
	int ma=0,mi=INF;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
	}
	if(check()){
		return ;
	}
	int cnt=0;
	vis[mi]=1;
	while(ma!=mi)
	{
		ma>>=1;
		mi>>=1;
		if(mi==0){
			cout<<-1<<endl;
			return ;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int x=a[i];
		while(!vis[x]){
			cnt++;
			x>>=1;
		}
	}
	cout<<cnt<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
5
3 4 4 4 4
*/