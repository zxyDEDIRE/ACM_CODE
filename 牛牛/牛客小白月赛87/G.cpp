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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Tree;

Tree t[maxn];
int p[maxn];
int a[maxn];
int n;

template<typename T>
int getRank(T x,int op)
{
	return t[op].order_of_key(x)+1;
}

template<typename T>
T getVal(int k,int op)
{
	auto it=t[op].find_by_order(k-1);
	if(it!=t[90].end())
		return *it;
	else
		return {INF,0};
}


ll merge_sort(int p[],int l,int r)
{
	if(l>=r)return 0;
	ll t=0;
	int mid=l+r>>1;
	t=merge_sort(p,l,mid)+merge_sort(p,mid+1,r);
	int temp[r-l+1];
	int k=0,i=l,j=mid+1;
	while(i<=mid&&j<=r)
	{
		if(p[i]<=p[j])temp[k++]=p[i++];
		else
		{
			t+=mid-i+1;
			temp[k++]=p[j++];
		}
	}
	while(i<=mid)temp[k++]=p[i++];
	while(j<=r)temp[k++]=p[j++];
	for(int i=l,j=0;i<=r;i++,j++)p[i]=temp[j];
	return t;
}
void solve()
{
	cin>>n;
	// n=2e5;
	for(int i=1;i<=n;i++){
		// cin>>p[i],a[i]=p[i];
		p[i]=a[i]=n-i+1;
	}
	ll res=merge_sort(a,1,n);
	// int res=0;
	for(int i=1;i<=n;i++)
	{
		int x=p[i];
		for(int j=2;j*j<=p[i];j++)
			if(p[i]%j==0)
			{
				t[j].insert(x);
				int _x = getRank<int>(x, j);
				// res-=_x;
				res-=t[j].size()-_x;
				// cout<<i<<" "<<p[i]<<" "<<j<<" "<<t[j].size()-_x<<endl;
				while(p[i]%j==0)
					p[i]/=j;
			}
		if(p[i]>1)
		{
			int j=p[i];
			t[j].insert(x);
			int _x = getRank<int>(x, j);
			res-=t[j].size()-_x;
			// cout<<i<<" "<<p[i]<<" "<<j<<" "<<t[j].size()-_x<<endl;
			// while(p[i]%j==0)
			// 	p[i]/=j;
		}
	}
	cout<<res<<endl;
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
j - o
o - j
j - j
*/