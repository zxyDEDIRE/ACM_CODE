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
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
bitset<maxn>vis;
vector<int>v;
stack<int>s;
int p[maxn];
int f[maxn];
int n,cnt;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void tarjan(int x)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	vis[x]=1;
	int num=0;
	int y=p[x];
	if(!dfn[y])
	{
		num++;
		tarjan(y);
		low[x]=min(low[x],low[y]);
	}
	else if(vis[y])
		low[x]=min(low[x],dfn[y]);
	if(low[x]==dfn[x])
	{
		tot++;
		int y;
		int cnt=0;
		do{
			y=s.top();
			s.pop();
			vis[y]=0;
			col[y]=tot;
			cnt++;
		}while(x!=y);
		v.push_back(cnt);
	}
}
void solve()
{
	cin>>n;
	indx=0;
	tot=0;
	v.clear();
	for(int i=1;i<=n;i++)
		cin>>p[i],f[i]=i,dfn[i]=0;
	for(int i=1;i<=n;i++)
	{
		int fa=find(i);
		int fb=find(p[i]);
		if(fa!=fb)f[fa]=fb;
	}
	int ma_cnt=0;
	for(int i=1;i<=n;i++)
		if(f[i]==i)ma_cnt++;
	vis.reset();
	int mi_cnt=0;
	int ano=0;
	for(int i=1;i<=n;i++)
		if(!dfn[i])tarjan(i);
	sort(v.begin(),v.end());
	// for(auto i:v)
	// 	cout<<i<<" ";cout<<endl;
	for(int i=(int)v.size()-1;i>=0;i--)
		if(v[i]>2)mi_cnt++;
		else ano=1;
	mi_cnt+=ano;
	cout<<mi_cnt<<" "<<ma_cnt<<endl;

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
9
2 3 2 5 6 5 8 9 8
1 2 3
4 5 6 
7 8 9 
*/