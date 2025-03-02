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
struct node{
	int pos,v;
}p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].pos>>p[i].v;
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.pos!=b.pos)
			return a.pos>b.pos;
		return a.v<b.v;
	});
	vector<pii>v;
	v.push_back({p[1].v,1});
	int pos=p[1].pos;
	for(int i=2;i<=n;i++)
	{
		auto &[y,num]=v.back();
		auto [_pos,x]=p[i];
		if(_pos==pos || x>y)
			num++;
		else v.push_back({x,1});
		pos=_pos;
	}
	int ma=1;
	for(auto [x,y]:v)
		ma=max(ma,y);
	cout<<ma<<endl;
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
1 1
1 2
2 3
3 2
6 1
*/