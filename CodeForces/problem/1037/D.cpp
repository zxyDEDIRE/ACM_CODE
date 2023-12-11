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
vector<int>v[maxn];
bitset<maxn>vis;
int le[maxn];
int in[maxn];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		cin>>p[i];
	queue<int>q;
	q.push(1);
	in[1]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=1;
		int fl=0;
		for(auto y:v[x])
		{
			if(vis[y])continue;
			in[y]=in[x]+1;
			q.push(y);
			fl=1;
		}
		if(!fl)le[x]=1;
	}
	int ma=0;
	for(int i=1;i<=n;i++)
	{
		if(in[p[i]]<ma){
			cout<<"No"<<endl;
			return ;
		}
		ma=max(ma,in[p[i]]);
	}
	vis.reset();
	for(int i=1;i<=n;i++)
		in[i]=0;
	for(int i=n;i>=1;i--)
	{
		vis[p[i]]=1;
		if(q.empty()||q.front()!=p[i])
		{
			if(le[p[i]])
			{
				for(auto y:v[p[i]])
					if(!vis[y]&&!in[y])
						q.push(y),in[y]=1;
			}
			else{
				cout<<"No"<<endl;
				return ;
			}
		}
		else
		{
			q.pop();
			for(auto y:v[p[i]])
				if(!vis[y]&&!in[y])
					q.push(y),in[y]=1;
		}
	}
	cout<<"Yes"<<endl;
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
/*

*/