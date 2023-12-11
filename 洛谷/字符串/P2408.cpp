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
class SAM{
public:
	vector<int>v[maxn];
	int ch[maxn][26],cnt[maxn],len[maxn],fa[maxn];
	int count[maxn];
	int tot=1,np=1;
	ll ans;
	void clear(){
		for(int i=0;i<=tot;i++){
			for(int j=0;j<26;j++)
				ch[i][j]=0;cnt[i]=len[i]=fa[i]=0;
		}tot=np=1;
	}
	void insert(const int&c){
		int p=np; np=++tot;
		len[np]=len[p]+1; cnt[np]=1;
		for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
		if(p==0)fa[np]=1;
		else{
			int q=ch[p][c];
			if(len[q]==len[p]+1)fa[np]=q;
			else{
				int nq=++tot;
				len[nq]=len[p]+1;
				fa[nq]=fa[q]; fa[q]=nq; fa[np]=nq;
				for(;p&&ch[p][c]==q;p=fa[p])ch[p][c]=nq;
				memcpy(ch[nq],ch[q],sizeof(ch[q]));
			}
		}
	}
	void insert(char*s){
		for(int i=0;s[i]!='\0';i++)
			insert(s[i]-'a');
	}
	void build(){
		for(int i=2;i<=tot;i++)
			v[fa[i]].push_back(i);
	}
	void get_cound(int x=1)
	{
		if(count[x])return ;
		count[x]=1;
		for(int i=0;i<26;i++){
			if(!ch[x][i])continue;
			get_cound(ch[x][i]);
			count[x]+=count[ch[x][i]];
		}
	}
	void dfs(int x)
	{
		for(auto y:v[x]){
			dfs(y);
			cnt[x]+=cnt[y];
		}
		if(cnt[x]>1)ans=max(ans,1ll*cnt[x]*len[x]);
	}
	void get_kth(int k)
	{
		int rt=1;
		while(k)
		{
			if(!k)break;
			for(int i=0;i<26;i++){
				if(ch[rt][i]){
					if(count[ch[rt][i]]>=k){
						cout<<(char)(i+'a');
						--k;
						rt=ch[rt][i];
						break;
					}
					else
						k-=count[ch[rt][i]];
				}
			}
		}cout<<"\n";
	}
	void debug(){
		for(int i=0;i<=tot;i++)
			for(int j=0;j<26;j++)
				if(ch[i][j])
					cout<<"ins "<<i<<" --"<<(char)(j+'a')<<"--> "<<ch[i][j]<<endl;
		for(int i=1;i<=tot;i++)
			cout<<"fail "<<i<<" -> "<<fa[i]<<endl;
		for(int i=1;i<=tot;i++)
			cout<<"len["<<i<<"]="<<len[i]<<endl;
	}
	void query()
	{
		ll ans=0;
		for(int i=2;i<=tot;i++)
			ans+=len[i]-len[fa[i]];
		cout<<ans<<endl;
	}
}sam;
char ch[maxn];
int n;
void solve()
{
	cin>>n>>ch;
	sam.insert(ch);
	sam.build();
	sam.query();
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}