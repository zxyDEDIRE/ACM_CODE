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
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int ch[maxn][26];
int num[maxn];
int p[maxn];
int tot=0,n,m;
void insert(string &str) 
{
	int rt=0;
	for(int i=0;i<str.size();i++)
	{
		int x=str[i]-'a';
		if(!ch[rt][x])ch[rt][x]=++tot;
		rt=ch[rt][x];
		p[rt]++;
	}
	p[rt]--;
	num[rt]++;
}
ll query(string &str)
{
	int rt=0,cnt=0,flag=0;
	for(int i=0;i<str.size();i++)
	{
		int x=str[i]-'a';
		if(!ch[rt][x]){
			flag=1;
			break;
		}
		rt=ch[rt][x];
		cnt+=num[rt];
	}
	if(!flag)cnt+=p[rt];
	return cnt;
}
void solve()
{
	// cin>>n>>m;
	// for(int i=0;i<=tot;i++){
	// 	for(int j=0;j<26;j++)
	// 		ch[i][j]=0;
	// 	p[i]=num[i]=0;
	// }
	// tot=0;
	// for(int i=1;i<=n;i++){
	// 	string str;cin>>str;
	// 	insert(str);
	// }
	// ll ans=1;
	// for(int i=1;i<=m;i++){
	// 	string str;cin>>str;
	// 	ll now=query(str);
	// 	ans=(ans*(now+1));
	// 	ans%=mod;
	// }
	// cout<<ans-6396<<endl;
	int a;
	cout<<(sizeof a)<<endl;
	long b;
	cout<<(sizeof b)<<endl;
	long long c;
	cout<<(sizeof c)<<endl;
	__int128 d;
	cout<<(sizeof d)<<endl;
	long double e;
	cout<<(sizeof e)<<endl;
	vector<int>v(1000,1);
	cout<<(sizeof v)<<" "<<v.size()<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// for(int i=1;i<=__;i++)
	{
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
/*
4 1
3 0 1 0 
1 1 
3 1 0 0 
3 1 1 0 
2 1 1 
*/