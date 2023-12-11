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
const int maxn=8e6+100;
int p[maxn];
int n,m,k,N;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void un(int x,int y){
	int fa=find(x);
	int fb=find(y);
	if(fa!=fb)p[fa]=fb;
}
void solve()
{
	cin>>n>>m>>k;
	N=n+m+10;
	for(int i=1;i<=N*2;i++)
		p[i]=i;
	for(int i=1;i<=k;i++)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		if(y1+1==y2)
		{
			un(x1+N,y1+n);
			un(x1,y1+n+N);
		}
		else
		{
			un(x1,y2+n);
			un(x1+N,y2+n+N);
		}
	}
	for(int i=1;i<=N;i++)
		if(find(i)==find(i+N)){
			cout<<"NO\n";
			return ;
		}
	cout<<"YES\n";
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