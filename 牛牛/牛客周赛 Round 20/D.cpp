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
vector<pii>a,b;
string s,t;
void dfs(int x,string now,string &str,vector<pii>&a)
{
	// cout<<x<<" "<<now<<endl;
	if(now!="")
		a.push_back({stoll(now),str.size()-now.size()});
	// cout<<str.size()<<" "<<x<<" "<<now<<endl;
	if(x>=str.size())
		return ;
	dfs(x+1,now+str[x],str,a);
	dfs(x+1,now,str,a);
}
void solve()
{
	cin>>s>>t;
	dfs(0,"",s,a);
	dfs(0,"",t,b);
	int mi=INF;
	for(auto [x1,y1]:a)
	{
		for(auto [x2,y2]:b)
		{
			if(x1>=x2&&x1%x2==0)
				mi=min(mi,y1+y2);
			if(x2>=x1&&x2%x1==0)
				mi=min(mi,y1+y2);
		}
	}
	if(mi==INF)cout<<-1<<endl;
	else cout<<mi<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}