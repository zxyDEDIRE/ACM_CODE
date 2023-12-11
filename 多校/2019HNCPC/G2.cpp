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
const int N=2e3+9;
priority_queue<int,vector<int>,greater<int> >q;
bitset<N>bt[N],st[N],ss;
vector<int>v;
int a[N][N];
int n,m;
void solve()
{
	while(!q.empty())q.pop();
	v.clear();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=m;i++)
		bt[i].reset(),st[i].reset();
	for(int i=1;i<=m;i++)
	{
		int qw=1;
		bt[i][1]=st[i][1]=1;
		for(int j=2;j<=n;j++)
			if(a[j][i]>=a[j-1][i])bt[i][j]=1;
		qw=bt[i].count();
		if(qw==n)q.push(i);
		else v.push_back(i);
		for(int j=2;j<=n;j++)
			if(a[j][i]>a[j-1][i])
				st[i][j]=1;
	}
	int num=0;
	ss.reset();
	vector<int>ans;
	while(!q.empty())
	{
		int x=q.top();q.pop();
		ans.push_back(x);
		for(int i=0;i<v.size();i++)
		{
			if(v[i]==INF)continue;
			bt[v[i]]|=st[x];
			int qw=bt[v[i]].count();
			if(qw==n)q.push(v[i]),v[i]=INF;
		}
	}
	if(ans.size()!=n)cout<<-1<<endl;
	else
	{
		for(auto i:ans)
			cout<<i<<" ";
		cout<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	while(cin>>n>>m)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}