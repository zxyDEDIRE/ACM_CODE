
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int maxn=5e5+100;
class SAM{
public:
	vector<int>v[maxn];
	int ch[maxn][26],siz[maxn],len[maxn],fa[maxn];
	int tot=1,np=1;
	void insert(const int&c){
		int p=np; np=++tot;
		len[np]=len[p]+1; siz[np]=1;
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
	void query(const char*s);
}sam;
char s[maxn],t[maxn];
int n,m;
void SAM::query(const char *s)
{	
	int rt=1;
	int L=0;
	int ma=0;
	for(int i=0;i<strlen(s);i++)
	{
		int tmp=s[i]-'a';
		while(rt&&!ch[rt][tmp])
			rt=fa[rt],L=len[rt];
		if(rt==0)
			rt=1;
		else
		{
			rt=ch[rt][tmp];
			L++;
		}
		ma=max(ma,L);
	}
	cout<<ma<<endl;
}
void solve()
{
	cin>>s>>t;
	sam.insert(s);
	sam.query(t);
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}