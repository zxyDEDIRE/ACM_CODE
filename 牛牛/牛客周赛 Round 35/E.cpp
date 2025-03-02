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
vector<int>v[maxn];
vector<pii>ans;
int len=0;
int p[maxn];
int n,m;
int ma=0;
void NO(){
	cout<<-1<<endl;
}
void f()
{
	for(int i=1;i<=ma;i++)
	{
		int A=v[i].size();
		for(int a=0;a<A;a++)
			for(int b=a+1;b<A;b++){
				if(len==m)return ;
				ans.push_back({v[i][a],v[i][b]}),len++;
			}
	}
}
void F()
{
	for(int i=1;i<=ma;i++)
	{
		for(auto x:v[i])
		{
			for(int j=1;j<(int)v[i-1].size();j++)
			{
				int y=v[i-1][j];
				if(len==m)return ;
				ans.push_back({x,y}),len++;
			}
		}
	}
}
void solve()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>p[i],ma=max(ma,p[i]);
		v[p[i]].push_back(i);
	}
	if(v[0].size()!=1)return NO();
	for(int i=0;i<ma;i++)
		if(v[i].size()==0)
			return NO();
	for(int i=1;i<=ma;i++)
	{
		int y=v[i-1][0];
		for(auto x:v[i])
			ans.push_back({x,y}),len++;
	}
	// if(ans.size()>m)return NO();

	f();
	F();

	if((int)ans.size()!=m)return NO();
	for(auto [x,y]:ans)
		cout<<x<<" "<<y<<endl;


}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}