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
const int maxn=1e6+100;
struct node{
	int x,y,a;
}p[maxn];
vector<int>v[maxn];
int in[maxn];
int t[maxn];
int n,m;
bool topsort()
{
	int cnt=0,tot=0;
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i),cnt++;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		t[x]=++tot;
		for(auto y:v[x])
		{
			in[y]--;
			if(!in[y])
				q.push(y),cnt++;
		}
	}
	return cnt==n;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		v[i].clear(),in[i]=0;
	for(int i=1;i<=m;i++)
	{
		int x,y,a;
		cin>>a>>x>>y;
		p[i]={x,y,a};
		if(a)v[x].push_back(y),in[y]++;
	}
	if(!topsort())cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		for(int i=1;i<=m;i++)
		{
			auto [x,y,a]=p[i];
			if(t[x]<t[y])cout<<x<<" "<<y<<endl;
			else cout<<y<<" "<<x<<endl;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}