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
struct node{
	string id;
	int dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
vector<int>v[100];
int p[maxn];
int n,m;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	string S=string(9,'9');
	for(int i=1,x;i<=8;i++)
	{
		cin>>x;
		S[x-1]=(char)(i+'0');
	}
	queue<node>q;
	set<string>vis;
	q.push({S,0});
	vis.insert(S);
	while(!q.empty())
	{
		auto [now,dis]=q.front();q.pop();
		if(now=="123456789"){
			cout<<dis<<endl;
			return ;
		}
		int x;
		for(int i=0;i<9;i++)
			if(now[i]=='9'){
				x=i+1;
				break;
			}
		for(auto y:v[x])
		{
			string t=now;
			swap(t[x-1],t[y-1]);
			if(vis.count(t))continue;
			vis.insert(t);
			q.push({t,dis+1});
		}
	}
	cout<<-1<<endl;
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
/*
3 9 2
1 2 3
*/