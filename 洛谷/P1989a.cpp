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
int in[maxn];
pii p[maxn];
int n,m;
inline void read(int &x){
   int s = 0, w = 1; char ch = getchar();
   while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar(); }
   while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
   x = s*w;
   return ;
}

inline void write(int x){
    if(x<0){
    	putchar('-');
		x=-x;
	}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}  
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>p[i].first>>p[i].second;
		in[p[i].first]++;
		in[p[i].second]++;		
	}
	for(int i=1;i<=m;i++)
	{
		int x=p[i].first;
		int y=p[i].second;
		if(in[x]<in[y])swap(x,y);
		else if(in[x]==in[y]&&y<x)swap(x,y);
		v[x].push_back(y);
	}
	int ans=0;
	for(int x=1;x<=n;x++)
	{
		vis.reset();
		for(auto y:v[x])
			vis[y]=1;
		for(auto y:v[x])
		{
			for(auto z:v[y])
				if(vis[z])ans++;
		}
	}
	cout<<ans<<endl;
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