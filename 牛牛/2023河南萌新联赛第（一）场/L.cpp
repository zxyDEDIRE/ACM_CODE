#include <ext/pb_ds/assoc_container.hpp>
#include<bits/stdc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
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


typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> Tree;
Tree t;

template<typename T>
int getRank(T x)
{
	return t.order_of_key(x)+1;
}

template<typename T>
T getVal(int k)
{
	auto it=t.find_by_order(k-1);
	if(it!=t.end())
		return *it;
	else
		return {INF,0};
}
int cnt[maxn];
int a[maxn];
int b[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	set<int>s;
	for(int i=1;i<=n;i++)
		cin>>a[i],cnt[a[i]]++,b[i]=a[i],s.insert(a[i]);
	sort(b+1,b+1+n);
	int mid=b[(n+1)/2];
	int _mid=n/2;
	int pre=0,suf=0;
	for(int i=b[1];i<mid;i++)pre+=cnt[i];
	for(int i=b[n];i>mid;i--)suf+=cnt[i];


	while(m--)
	{
		int x,w;
		cin>>x>>w;
		cnt[a[x]]--;
		if(a[x]<mid)pre--;
		if(a[x]>mid)suf--;

		a[x]=w;
		cnt[w]++;
		s.insert(w);
		if(w<mid)pre++;
		if(w>mid)suf++;

		while(pre>_mid)
		{
			if(cnt[mid])suf+=cnt[mid];
			auto _x=s.lower_bound(mid);
			// mid--;
			_x--;
			mid=*_x;
			if(cnt[mid])pre-=cnt[mid];
		}

		while(suf>_mid)
		{
			if(cnt[mid])pre+=cnt[mid];
			auto _x=s.lower_bound(mid);
			// mid++;
			_x++;
			mid=*_x;
			if(cnt[mid])suf-=cnt[mid];
		}

		cout<<mid<<endl;
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
/*
1 3 3 4 5 6 1

5 1
11000
*/