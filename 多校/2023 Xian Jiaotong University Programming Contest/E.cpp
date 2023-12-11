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
double dis[333][333];
vector<int>v[333];
int dfn[maxn],low[maxn],indx;
int num[maxn],tot;
bitset<maxn>vis;
stack<int>s;
double b;
int n;
double read()
{
	string str;cin>>str;
	int fl=1,F=1;
	double a=0,t=1;
	if(str[0]=='-')fl=-1;
	for(auto i:str)
	{
		if(i=='+'||i=='-')continue;
		if(i=='.')F=2,t*=0.1;
		else if(F==1)
		{
			a=a*10+i-'0';
		}
		else if(F==2)
		{
			a+=(i-'0')*t;
			t*=0.1;
		}
	}
	return a*fl;
}
void tarjan(int x)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	vis[x]=1;
	for(auto y:v[x])
	{
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x])
	{
		tot++;
		int y;
		do{
			y=s.top();s.pop();
			num[tot]++;
			vis[y]=0;
		}while(y!=x);
	}
}
void solve()
{
	cin>>n;
	indx=tot=0;
	for(int i=1;i<=n;i++)
		dfn[i]=low[i]=0,v[i].clear(),num[i]=0;
	b=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=read();
	for(int i=1;i<=n;i++)
	{
		int tmp=0;dis[i][0]=-INF;
		for(int j=1;j<=n;j++)
			if(i!=j&&dis[i][j]>dis[i][tmp])
				tmp=j;
		if(dis[i][tmp]>=b){
			v[i].push_back(tmp);
		}
	}
	if(n==1)
	{
		cout<<"kono jinsei, imi ga nai!"<<endl;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=tot;i++)
		if(num[i]==1){
			cout<<"hbxql"<<endl;
			return ;
		}
	cout<<"wish you the best in your search"<<endl;
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
1->2
2->3
3->1

*/