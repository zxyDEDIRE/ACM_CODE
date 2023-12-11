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
struct node{
	string s;int id;
};
vector<node>p;
vector<int>nxt;
vector<ll>ans;
int n;
void init(const string &s,vector<int>&nxt)
{
	int len=s.size();
	nxt.resize(len+1);
	nxt[1]=0;
	for(int i=2;i<=len;i++)
	{
		nxt[i]=nxt[i-1];
		while(s[nxt[i]]!=s[i-1]&&nxt[i])
			nxt[i]=nxt[nxt[i]];
		if(s[nxt[i]]==s[i-1])nxt[i]++;
	}
}
int kmp(const string&s,const string&t,const vector<int>&nxt)
{
	int lens=s.size();
	int lent=t.size();
	int cnt=0;
	for(int i=0,j=0;i<lens;i++)
	{
		while(j&&s[i]!=t[j])j=nxt[j];
		if(s[i]==t[j])j++;
		if(j==lent){
			cnt++;
			j=nxt[j];
		}
	}
	return cnt;
}
void solve()
{
	cin>>n;
	p.resize(n);
	ans.resize(n);
	for(int i=0;i<n;i++)
		cin>>p[i].s,p[i].id=i;
	sort(p.begin(),p.end(),[&](node &a,node &b){
		if(a.s.size()!=b.s.size())return a.s.size()<b.s.size();
		return a.s<b.s;
	});
	int l=0,r=0;
	for(int i=0;i<n;i++)
		if(p[i].s.size()==p[0].s.size())
			r=i;
	if(p[l].s!=p[r].s){
		for(int i=0;i<n;i++)
			cout<<0<<endl;
		return ;
	}
	else if(r==n-1){
		for(int i=0;i<n;i++)
			cout<<1<<endl;
		return ;
	}

	init(p[0].s,nxt);
	ll res=1;
	for(int i=r+1;i<n;i++)
	{
		res*=kmp(p[i].s,p[0].s,nxt);
		res%=mod;
	}
	for(int i=l;i<=r;i++)
		ans[p[i].id]=res;
	for(int i=0;i<n;i++)
		cout<<ans[i]<<endl;


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

*/