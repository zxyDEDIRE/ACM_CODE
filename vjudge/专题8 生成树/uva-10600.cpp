#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
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
pp(4) p[maxn];
int n,m,ans_1,ans_2;
void solve()
{
	cin>>n>>m;
	ans_1=0,ans_2=INF;
	dsu.init(n);
	for(int i=1;i<=m;i++)
		for(int j=0;j<3;j++)
			cin>>p[i][j],p[i][3]=0;
	sort(p+1,p+1+m,[&](pp(4)x,pp(4)y){
		return x[2]<y[2];
	});
	for(int i=1;i<=m;i++)
	{
		auto [x,y,w,fl]=p[i];
		if(!dsu.same(x,y))
		{
			ans_1+=w;
			p[i][3]=1;
			dsu.merge(x,y);
		}
	}	
	for(int i=1;i<=m;i++)
	{
		if(!p[i][3])continue;
		int now=0;
		dsu.init(n);
		for(int j=1;j<=m;j++)
		{
			if(i==j)continue;
			auto [x,y,w,fl]=p[j];
			if(!dsu.same(x,y))
			{
				now+=w;
				dsu.merge(x,y);
			}
		}
		ans_2=min(ans_2,now);
	}
	cout<<ans_1<<" "<<ans_2<<endl;
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
/*
3 3
1 2 1
1 3 1
2 3 10
*/