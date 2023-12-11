/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
int p[100];
int n,m;
struct node{
	vector<int>v;
	bool operator<(const node&a)const{
		for(int i=0;i<n;i++)
			if(a.v[i]!=v[i])
				return a.v[i]<v[i];
		return 1;
	}
};
set<vector<int>>s;
void dfs(int x,int y)
{
	if(x==n){
		// cout<<p[1]<<" "<<y<<endl;
		vector<int>v;
		for(int i=1;i<n;i++)
			v.push_back(p[i]);
		v.push_back(y);
		s.insert(v);
		return ;
	}
	for(int i=0;i<=y;i++)
	{
		p[x]=i;
		dfs(x+1,y-i);
	}
}
void solve()
{
	cin>>n>>m;
	dfs(1,m);
	cout<<s.size();
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