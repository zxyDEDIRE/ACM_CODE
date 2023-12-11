/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
	int x,y;
	bool operator<(const node&a)const{
		if(a.x!=x)return a.x<x;
		return a.y<y;
	}
};
map<int,priority_queue<node>>q;
map<int,vector<pii>>v;
map<int,int>mp;
int cnt[maxn];
int g,n;
void solve()
{
	cin>>g;
	for(int i=1;i<=g;i++)
	{
		int x,y;
		cin>>x>>y;
		mp[x]=y;
	}
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int m,k;
		cin>>m;
		while(m--)
		{
			int x,y;
			cin>>x>>y;
			if(mp[x]<y)cnt[i]++,q[x].push({y,i});
		}
		cin>>k;
		while(k--)
		{
			int x,y;
			cin>>x>>y;
			v[i].push_back({x,y});
		}
	}
	queue<int>Q;
	for(int i=1;i<=n;i++)
		if(cnt[i]==0){
			Q.push(i);
		}
	int ans=0;
	while(!Q.empty())
	{
		int now=Q.front();
		Q.pop();
		ans++;
		for(auto [x,y]:v[now])
		{
			mp[x]+=y;
			while(!q[x].empty())
			{
				auto [ned,id]=q[x].top();
				if(mp[x]>=ned)
				{
					q[x].pop();
					cnt[id]--;
					if(cnt[id]==0)
						Q.push(id);
				}
				else break;
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}