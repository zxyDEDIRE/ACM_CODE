/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
vector<int>v[maxn];
bitset<maxn>vis;
int num[maxn];
int in[maxn];
int out[maxn];
int n;
void NO(){cout<<-1<<endl;}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		num[i]=1;
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
		in[x]++;
		in[y]++;
	}
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(in[i]==1)q.push(i);
	int cnt=n;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=1;
		cnt--;
		for(auto y:v[x])
		{
			if(vis[y])continue;
			in[y]--;
			num[y]+=num[x];
			if(in[y]==1)q.push(y);
		}
	}
	if(n!=0&&cnt%4!=0)return NO();
	vector<int>u;
	for(int i=1;i<=n;i++)
		if(!vis[i])
			u.push_back(i);
	vis.reset();
	for(auto i:u)
		cout<<num[i]<<" ";cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
15
1 2
2 5
5 6
6 9
9 12
12 4
4 3
3 1
6 7
7 8
9 10
10 11
12 13
13 14
14 15
*/