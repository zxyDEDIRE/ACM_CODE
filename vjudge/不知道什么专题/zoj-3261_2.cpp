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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	char s[15];
	int x, y;
} qry[maxn];
map<pii,bool>mp;
pii ve[maxn];
int f[maxn], w[maxn];
int ans[maxn];
int n,m,q;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}

void unio(int a, int b)
{
	int pa = find(a), pb = find(b);
	if(pa != pb)
	{
		if(w[pa] > w[pb])
			f[pb] = pa;
		else if(w[pa] < w[pb])
			f[pa] = pb;
		else if(pa < pb)
			f[pb] = pa;
		else
			f[pa] = pb;
	}
}


void solve()
{
	for(int i = 0; i < n; i++)
		cin>>w[i],f[i]=i;
	cin>>m;

	mp.clear();

	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin>>a>>b;
		ve[i].first = a, ve[i].second = b;
	}
	cin>>q;
	for(int i = 1; i <= q; i++)
	{
		cin>>qry[i].s;
		if(qry[i].s[0] == 'q')
			cin>>qry[i].x;
		else
		{
			cin>>qry[i].x>>qry[i].y;
			mp[make_pair(qry[i].x, qry[i].y)] = 1;
			mp[make_pair(qry[i].y, qry[i].x)] = 1;
		}
	}

	for(int i = 0; i < m; i++)
	{
		if(mp[make_pair(ve[i].first, ve[i].second)] == 0)
			unio(ve[i].first, ve[i].second);
	}

	vector<int>ans;
	for(int i = q; i >= 1; i--)
	{
		if(qry[i].s[0] == 'd')
			unio(qry[i].x, qry[i].y);
		else
		{
			int px = find(qry[i].x);
			if(w[px] > w[qry[i].x])
				ans.push_back(px);
			else
				ans.push_back(-1);
		}
	}
	reverse(ans.begin(),ans.end());
	for(auto i:ans)
		cout<<i<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int flag=0;
	while(cin>>n){
		if(flag)cout<<endl;
		solve();
		flag=1;
	}
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
