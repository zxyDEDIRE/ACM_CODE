#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
const int maxn=3e6+100;
map<int,ll>t[maxn];
vector<pii>v[maxn];
vector<int>sum[maxn];
map<ll,int>root;
int num[maxn];
int n,q,indx;
inline vector<ll>get_num(ll x,ll y)
{
	vector<ll>w;
	while(1){
		if(x==y)break;
		else if(x>y){
			ll pre=x;
			x%=y;if(!x)x=y;
			w.push_back((pre-x)/y);
			w.push_back(-1);
		}
		else{
			ll pre=y;
			y%=x;if(!y)y=x;
			w.push_back((pre-y)/x);
			w.push_back(-2);
		}
	}
	w.push_back(x);
	reverse(w.begin(),w.end());
	return w;
}
inline void insert(vector<ll>w)
{
	if(!root.count(w[0]))
		root[w[0]]=++indx;
	int rt=root[w[0]];
	for(auto x:w)
	{
		if(!t[rt].count(x))
			t[rt][x]=++indx;
		v[rt].push_back(pii{x,t[rt][x]});
		rt=t[rt][x];
		num[rt]++;
	}
}
inline ll query(vector<ll>w)
{
	if(!root.count(w[0]))return 0;
	int rt=root[w[0]];
	int len=w.size();
	for(int i=0;i<len-1;i++)
	{
		if(!t[rt].count(w[i]))return 0;
		rt=t[rt][w[i]];
	}
	if(w.size()==1)return sum[rt].back();
	ll fl=lower_bound(v[rt].begin(),v[rt].end(),pii{w.back(),0})-v[rt].begin();
	if(fl==v[rt].size())return 0;
	if(fl==0)return sum[rt].back();
	return sum[rt].back()-sum[rt][fl-1];
}
inline void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		ll x,y;
		cin>>x>>y;
		vector<ll>w=get_num(x,y);
		insert(w);
	}
	for(int i=0;i<=indx;i++)
	{
		if(v[i].size()==0)continue;
		sort(v[i].begin(),v[i].end());
		v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
		sum[i].resize(v[i].size());
		sum[i][0]=num[v[i][0].second];
		for(int j=1;j<(int)v[i].size();j++)
			sum[i][j]=sum[i][j-1]+num[v[i][j].second];
	}
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		vector<ll>w=get_num(x,y);
		cout<<query(w)<<endl;
	}


	for(int i=0;i<=indx;i++)
		v[i].clear(),t[i].clear(),num[i]=0,sum[i].clear();
	indx=0;
	root.clear();
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	ll __;cin>>__;
	while(__--)solve();
	return 0;
}