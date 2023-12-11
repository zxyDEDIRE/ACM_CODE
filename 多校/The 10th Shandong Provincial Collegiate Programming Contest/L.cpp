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
vector<int>v[maxn];
int in1[maxn],in2[maxn];
int a[maxn],b[maxn];
bitset<maxn>vis;
int f[maxn];
int n,m,flag;
void init(){
	for(int i=1;i<=n;i++){
		v[i].clear();
		a[i]=b[i]=vis[i]=in1[i]=in2[i]=0;
		f[i]=i;
	}
	flag=0;
}
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void merge(int x,int y){
	int fa=find(x),fb=find(y);
	if(fa!=fb)f[fa]=fb;
}
void topsort(int F)
{
	priority_queue<int,vector<int>,greater<int>>q2;
	priority_queue<int,vector<int>,less<int>>q1;
	int num=0,cnt1=0,cnt2=0;
	vector<int>p;
	for(int i=1;i<=n;i++)
		if(find(i)==F){
			p.push_back(i);
			vis[i]=1;
			num++;
			if(in1[i]==0){
				q1.push(i);
				q2.push(i);
			}
		}
	while(!q1.empty()){
		int x=q1.top();q1.pop();
		a[x]=++cnt1;
		for(auto y:v[x]){
			in1[y]--;
			if(!in1[y])q1.push(y);
		}
	}
	while(!q2.empty()){
		int x=q2.top();q2.pop();
		b[x]=++cnt2;
		for(auto y:v[x]){
			in2[y]--;
			if(!in2[y])q2.push(y);
		}
	}
	for(auto x:p)
	{
		if(a[x]>b[x])swap(a[x],b[x]);
		b[x]+=(n-num);
		if(in1[x]||in2[x])flag=1;
	}
}
void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++)
	{
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		merge(x,y);
		if(x==y)flag=1;
		in1[y]++;
		in2[y]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		topsort(find(i));
	}
	if(flag){
		for(int i=1;i<=n;i++)
			cout<<"0";cout<<endl;
		return ;
	}
	// for(int i=1;i<=n;i++)
	// 	cout<<a[i]<<" \n"[i==n];
	// for(int i=1;i<=n;i++)
	// 	cout<<b[i]<<" \n"[i==n];

	int mid=(1+n)/2;
	for(int i=1;i<=n;i++)
		if(a[i]<=mid&&b[i]>=mid)cout<<"1";
		else cout<<"0";
	cout<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
7 6
1 2 
2 3
3 4
1 5
5 6
6 4
*/