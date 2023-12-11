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
int a[maxn];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	dsu.init(n);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,[&](int a,int b){return a>b;});
	for(int i=1;i<=n;i++)
	{
		int x=a[i];
		if(p[x]){
			dsu.merge(p[x],i);
			continue;
		}
		for(int j=1;j*x<=a[1];j++)
			if(p[j*x]){
				dsu.merge(p[j*x],i);
			}
		if(!p[x])p[x]=i;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(dsu.find(i)==i)
			cnt++;
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