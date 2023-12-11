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
const int maxn=2e6+100;
int t[maxn][26],tot;
int vis[maxn];
int w[maxn];
int n,k,flag;
void clear()
{
	for(int i=0;i<=tot;i++)
	{
		for(int j=0;j<26;j++)
			t[i][j]=0;
		vis[i]=w[i]=0;
	}
	tot=0;
}
void insert(const string&str)
{
	int rt=0;
	for(int i=0;i<str.size();i++)
	{
		int tmp=str[i]-'a';
		if(!t[rt][tmp])
			t[rt][tmp]=++tot;
		rt=t[rt][tmp];
		w[rt]++;
	}
	vis[rt]++;
}
void dfs(int rt,int num)
{
	int now=0;
	for(int i=0;i<26;i++)
		now+=min(1,w[t[rt][i]]);
	num-=vis[rt];
	if(now>=num)
		return ;
	if(num<=1)return ;

	for(int i=0;i<26;i++)
	{
		if(w[t[rt][i]]&&w[t[rt][i]]+now-1>=num)
		{
			flag=1;
			cout<<(char)('a'+i);
			dfs(t[rt][i],num-now+1);
			return ;
		}
		else if(w[t[rt][i]]){
			num-=w[t[rt][i]];
			now--;
		}
	}
}
void solve()
{
	cin>>n>>k;
	clear();
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		insert(str);
	}
	flag=0;
	dfs(0,k);
	if(!flag) cout<<"EMPTY\n";
	else cout<<"\n";
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
1
6 3
aaa
aaa
aab
aca
acb
acb
*/