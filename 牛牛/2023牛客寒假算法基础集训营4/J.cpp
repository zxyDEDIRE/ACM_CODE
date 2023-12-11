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
vector<int>v[maxn];
int dis_a[maxn];
int dis_b[maxn];
int in_a[maxn];
int in_b[maxn];
int n,m;
void A()
{
	priority_queue<int,vector<int>,greater<int>>q;
	for(int i=1;i<=n;i++)
		if(!in_a[i])
			q.push(i);
	int now=0;
	while(!q.empty())
	{
		int x=q.top();q.pop();
		dis_a[++now]=x;
		for(auto y:v[x])
		{
			in_a[y]--;
			if(!in_a[y])
				q.push(y);
		}
	}
	// cout<<"C"<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<dis_a[i]<<" ";cout<<endl;
}
void B()
{
	priority_queue<int>q;
	for(int i=1;i<=n;i++)
		if(!in_b[i])
			q.push(i);
	int now=0;
	while(!q.empty())
	{
		int x=q.top();q.pop();
		dis_b[++now]=x;
		for(auto y:v[x])
		{
			in_b[y]--;
			if(!in_b[y])
				q.push(y);
		}
	}
	// cout<<"D"<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<dis_b[i]<<" ";cout<<endl;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		in_a[y]++;
		in_b[y]++;
	}
	A();
	B();
	for(int i=1;i<=n;i++)
	{
		if(dis_a[i]==dis_b[i])cout<<dis_a[i]<<" ";
		else cout<<-1<<" ";
	}	
	cout<<endl;
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