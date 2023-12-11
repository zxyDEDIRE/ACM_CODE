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
const int maxn=1e7+100;
int ch[maxn][2];
int num[maxn];
int p[maxn];
int tot=0,n,m;
void insert() 
{
	int len;cin>>len;
	int rt=0;
	// cout<<"len "<<len<<endl;
	for(int i=0;i<len;i++)
	{
		int x;cin>>x;
		if(!ch[rt][x])ch[rt][x]=++tot;
		// if(len==18)cout<<rt<<" "<<ch[rt][x]<<endl;
		rt=ch[rt][x];
		p[rt]++;
	}
	p[rt]--;
	num[rt]++;
}
void query()
{
	int len;cin>>len;
	int rt=0,cnt=0,flag=0;
	// cout<<"len "<<len<<endl;
	for(int i=0;i<len;i++)
	{
		int x;cin>>x;
		if(!ch[rt][x]){
			flag=1;i++;
			while(i<len)cin>>x,i++;
			break;
		}
		rt=ch[rt][x];
		cnt+=num[rt];
	}
	if(!flag)cnt+=p[rt];
	cout<<cnt<<endl;
}
void solve()
{
	cin>>n>>m;
	// n=30;m=0;
	for(int i=1;i<=n;i++){
		// cout<<i<<" ";
		insert();
		// cout<<i<<endl;
	}
	// cout<<"qu";
	for(int i=1;i<=m;i++){
		query();
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
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