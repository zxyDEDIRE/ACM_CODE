/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int x,y;
	bool operator<(const node&a)const{
		return x*(a.y)<y*a.x;
	}
	bool operator<=(const node&a)const{
		return x*(a.y)<=y*a.x;
	}
};
void solve()
{
	int n;
	cin>>n;
	vector<pair<node,node>>v(n);
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		// v[i]={{y,x-1},{y-1,x}};
		v[i]=make_pair(node{y,x-1},node{y-1,x});
	}
	sort(v.begin(),v.end());
	node now={0,1};
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(now<=v[i].second)
		{
			ans++;
			now=v[i].first;
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}