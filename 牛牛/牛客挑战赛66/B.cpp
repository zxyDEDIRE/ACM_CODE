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
int siz[maxn];
int ans[maxn];
int n,fl,cnt,now;
void dfs1(int x,int fa)
{
	siz[x]=1;
	int cnt_1=0,cnt_2=0;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs1(y,x);
		siz[x]+=siz[y];
		cnt_1++;
		if(siz[y]==1)
			cnt_2++;
	}
	if(cnt_1==cnt_2&&cnt_1&&siz[x]<siz[fl])
		fl=x;
	if(siz[x]==1)cnt++;
}
void dfs2(int x,int fa)
{
	if(cnt%2==1&&x==fl)return ;
	if(siz[x]==1&&now){
		ans[x]=1;
		now--;
		return ;
	}
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs2(y,x);
		ans[x]=(ans[y]^1);
	}
}
void solve()
{
	cin>>n;
	fl=n+1;
	if(n<=2){
		cout<<"NO"<<endl;
		return ;
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	siz[n+1]=n+1;
	dfs1(1,1);
	now=(cnt+1)/2;
	if(cnt%2==1&&siz[fl]>(cnt/2)){
		cout<<"NO"<<endl;
		return ;
	}
	dfs2(1,1);
	if(now){
		cout<<"NO"<<endl;
		return ;
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
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