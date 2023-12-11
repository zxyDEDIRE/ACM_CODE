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
	int op,x,y;
}a[maxn];
map<pii,bool>mp;
pii p[maxn];
int w[maxn];
int f[maxn];
int n,m,q;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void un(int x,int y)
{
	int fa=find(x);
	int fb=find(y);
	if(fa==fb)return ;
	if(w[fa]>w[fb])f[fb]=fa;
	else if(w[fa]<w[fb])f[fa]=fb;
	else if(w[fa]==w[fb])
	{
		if(fa<fb)f[fb]=fa;
		else f[fa]=fb;
	}
}
void solve()
{
	mp.clear();
	for(int i=0;i<n;i++)
		cin>>w[i],f[i]=i;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>p[i].first>>p[i].second;
		if(p[i].first>p[i].second)
			swap(p[i].first,p[i].second);
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		string op;
		cin>>op;
		if(op=="destroy"){
			a[i].op=1;
			cin>>a[i].x>>a[i].y;
			if(a[i].x>a[i].y)swap(a[i].x,a[i].y);
			mp[{a[i].x,a[i].y}]=1;
		}
		else{
			a[i].op=-1;
			cin>>a[i].x;
		}
	}
	for(int i=1;i<=m;i++){
		if(!mp.count(p[i])){
			un(p[i].first,p[i].second);
		}
	}
		
	vector<int>ans;
	for(int i=q;i>=1;i--)
	{
		auto [op,x,y]=a[i];
		if(op==1)un(x,y);
		else if(op==-1)
		{
			int fa=find(x);
			if(w[fa]>w[x])ans.push_back(fa);
			else ans.push_back(-1);
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
