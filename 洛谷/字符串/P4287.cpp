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
const int maxn=8e5+100;
class PAM{
public:
	vector<int>v[maxn];
	int s[maxn],now;
	int ch[maxn][26],fa[maxn],len[maxn],last,tot;
	int vis[maxn];
	int num[maxn];
	int pre=0;
	int ans;
	void clear()
	{
		s[0]=len[1]=-1;
		fa[0]=tot=now=1;
		last=len[0]=0;
		memset(ch[0],0,sizeof(ch[0]));
		memset(ch[1],0,sizeof(ch[1]));
	}
	PAM(){clear();}
	int newnode(int length){
		tot++;
		memset(ch[tot],0,sizeof(ch[tot]));
		fa[tot]=num[tot]=0;
		len[tot]=length;
		return tot;
	}
	int get_fail(int rt){
		while(s[now-len[rt]-2]!=s[now-1])rt=fa[rt];
		return rt;
	}
	void insert(int c)
	{
		s[now++]=c;
		int rt=get_fail(last);
		if(!ch[rt][c]){
			int np=newnode(len[rt]+2);
			fa[np]=ch[get_fail(fa[rt])][c];
			ch[rt][c]=np;
			// num[np]=num[fa[np]]+1;
		}
		last=ch[rt][c];
		num[last]++;
	}
	void build(){
		for(int i=tot;i>=2;i--)
			num[fa[i]]+=num[i];
		num[0]=num[1]=0;
	}
	void build_tree(){
		for(int i=2;i<=tot;i++)
			v[fa[i]].push_back(i);
		v[1].push_back(0);
	}
	void insert(char*s){while(*s){insert(*s-'a');s++;}}
	void insert(const string&s){for(auto i:s)insert(i-'a');}
	void debug(){
		for(int i=0;i<=tot;i++)
			for(int j=0;j<26;j++)
				if(ch[i][j])
					cout<<"ins "<<i<<" --"<<(char)(j+'a')<<"--> "<<ch[i][j]<<endl;
		for(int i=0;i<=tot;i++)
			cout<<"len["<<i<<"]="<<len[i]<<endl;
		for(int i=0;i<=tot;i++)
			cout<<"fa["<<i<<"]="<<fa[i]<<endl;
	}
	void dfs(int x);
	void query();
}pam;
string str;
int n;
void PAM::dfs(int x=1)
{
	if(len[x]%4==0 && vis[len[x]/2])ans=max(ans,len[x]);
	for(auto y:v[x])
	{
		if(len[y]%2==0)vis[len[y]]++;
		dfs(y);
		if(len[y]%2==0)vis[len[y]]--;
	}
}
void solve()
{
	cin>>n;
	cin>>str;
	pam.insert(str);
	pam.build_tree();
	pam.dfs();
	cout<<pam.ans<<endl;;
	// pam.debug();
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
abbaabba
abaabaabaaba
*/