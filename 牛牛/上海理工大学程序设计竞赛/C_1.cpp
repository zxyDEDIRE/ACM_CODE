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
string T="lenovo";
int t[maxn][26],indx;
int p[maxn];
int a[maxn];
int sum;
void insert(string&str)
{
	int rt=0,len=str.size();
	int suf=-1;
	for(int i=len-6;i>=0&&suf==-1;i--)
		if(str.substr(i,6)==T)
			suf=i,sum++;

	for(int i=0;i<len;i++)
	{
		int tmp=str[i]-'a';
		if(!t[rt][tmp])
			t[rt][tmp]=++indx;
		rt=t[rt][tmp];
		if(suf!=-1&&i>=suf)
			p[rt]++;
	}
}
void query(string &str)
{
	int rt=0;
	int len=str.size();
	int ans=sum;
	int flag=1;
	// cout<<endl;
	for(int i=0;i<len;i++)
	{
		int tmp=str[i]-'a';
		if(!t[rt][tmp])
			break;
		rt=t[rt][tmp];
		if(i+1==len)
			ans-=p[rt];
	}
	cout<<ans<<endl;
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int op;string str;
		cin>>op>>str;
		if(op==1)insert(str);
		else query(str);
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
5
1 ilovelenovo
1 ilovlenovo
1 ilolenovo
1 illenovo
2 ilol

4
1 ilovelenovo
1 ilovlenovo
1 ilolenovo

2
1 illenovo
2 ilol
*/