#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<pii>mp(maxn);
struct node{int x,y;ll w;};
vector<node>v;
int p[maxn];
int n,c;
ll f(int x,int y){
	ll dis=(mp[x].fi-mp[y].fi)*(mp[x].fi-mp[y].fi);
	dis+=(mp[x].se-mp[y].se)*(mp[x].se-mp[y].se);
	return dis;
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int r){
	return p[r]=(p[r]==r)?p[r]:find(p[r]);
}
void solve()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		mp[i].fi=x;
		mp[i].se=y;
		p[i]=i;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			ll F=f(i,j);
			if(F>=c)v.push_back({i,j,F});
		}
	}
	sort(v.begin(),v.end(),cmp);
	int cnt=1;
	ll ans=0;
	for(auto i:v){
		int fa=find(i.x);
		int fb=find(i.y);
		if(fa!=fb){
			p[fa]=fb;
			ans+=i.w;
			cnt++;
		}
		if(cnt==n)break;
	}
	if(cnt!=n)cout<<-1<<endl;
		else 
	cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;
//    cin>>__;
    __=1;
    while(__--)solve();
    return 0;
}