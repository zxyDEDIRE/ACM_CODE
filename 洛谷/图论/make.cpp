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
class DSU{
public:
	vector<int>f,num;
	DSU(){}
	void init(int n){
		f.resize(n+1);
		iota(f.begin(),f.end(),0);
	}
	int find(int r){
		return f[r]=f[r]==r?f[r]:find(f[r]);
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	void merge(int x,int y){
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)
			f[fa]=fb;
	}
}dsu;
void solve()
{
	int n,m,k;
	n=10;
	m=20;
	k=20;
	
	vector<pp(3)>v;
	while(1)
	{
		dsu.init(n);
		v.clear();
		for(int i=1;i<=m;i++)
		{
			int x=rand()%n+1;
			int y=rand()%n+1;
			int w=rand();
			v.push_back({x,y,w});
			dsu.merge(x,y);
		}
		if(dsu.same(1,n))break;
	}
	cout<<n<<" "<<m<<" "<<k<<endl;
	for(auto [x,y,w]:v)
		cout<<x<<" "<<y<<" "<<w<<endl;
	for(int i=1;i<=m;i++)
	{
		int x=rand()%m+1;
		int w=rand();
		cout<<x<<" "<<w<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}