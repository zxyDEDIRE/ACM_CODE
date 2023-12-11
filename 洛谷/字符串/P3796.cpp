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
vector<string>p;
struct ACAM{
	int ch[maxn][26],nxt[maxn];
	int val[maxn],cnt[maxn];
	int id[maxn],q[maxn];
	int root=0,indx=0;
	int top=0,low=1;
	void clear(){
		for(int i=0;i<=indx;i++){
			val[i]=cnt[i]=id[i]=q[i]=nxt[i]=0;
			for(int j=0;j<26;j++)
				ch[i][j]=0;
		}
		indx=top=0;low=1;
	}
	void insert(const string &str,int x)
	{
		int rt=0;
		for(int i=0;i<str.size();i++){
			int tmp=str[i]-'a';
			if(!ch[rt][tmp])ch[rt][tmp]=++indx;
			rt=ch[rt][tmp];
		}
		// cout<<"id "<<x<<" "<<rt<<endl;
		val[rt]++;
		id[x]=rt;
	}
	void build()
	{
		for(int i=0;i<26;i++)
			if(ch[0][i])
				q[++top]=ch[0][i];
		while(low<=top){
			int x=q[low++];
			for(int i=0;i<26;i++){
				int &rt=ch[x][i];
				if(!rt)rt=ch[nxt[x]][i];
				else{
					nxt[rt]=ch[nxt[x]][i];
					q[++top]=rt;
				}
			}
		}
	}
	void query(string &s,int x)
	{
		int rt=0;
		int ma=0;
		for(int i=0;i<s.size();i++)
		{
			int tmp=s[i]-'a';
			rt=ch[rt][tmp];
			for(int t=rt;t;t=nxt[t]){
				cnt[t]+=val[t];
				ma=max(ma,cnt[t]);
			}
		}
		cout<<ma<<endl;
		if(ma==0)return ;
		for(int i=0;i<x;i++)
			if(cnt[id[i]]==ma)
				cout<<p[i]<<endl;
	}
}ac;
string t;
int n;
void solve()
{
	while(cin>>n&&n)
	{
		ac.clear();
		p.resize(n);
		for(int i=0;i<n;i++)
		{
			cin>>p[i];
			ac.insert(p[i],i);
		}
		ac.build();
		cin>>t;
		ac.query(t,n);
	}
	

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}
/*
10
qabqks
vimbirqy
cflwvxtp
klljfj
ab
nkeiid
fkypjfev
yvgp
evdhs
xaizql
qabqksatffqpjomzstjabfklljfjqevdhsqabqkscflwvxtpeevdhsmzonkeiid
*/