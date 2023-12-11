#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
const int maxn=1e6+100;
const int N=2022;
int ans[N][N];
class SAM{
public:
	int ch[maxn][26],len[maxn],fa[maxn];
	int f[maxn];
	int tot=1,np=1;
	ll ans;
	void clear(){
		for(int i=0;i<=tot;i++){
			for(int j=0;j<26;j++)
				ch[i][j]=0;len[i]=fa[i]=0;
		}tot=np=1;
		ans=0;
	}
	void insert(const int&c){
		int p=np; np=++tot;
		len[np]=len[p]+1;
		for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
		if(p==0)fa[np]=1,ans+=len[np]-len[fa[np]];
		else{
			int q=ch[p][c];
			if(len[q]==len[p]+1)fa[np]=q,ans+=len[np]-len[fa[np]];
			else{
				int nq=++tot;
				len[nq]=len[p]+1;
				ans-=len[q]-len[fa[q]];
				fa[nq]=fa[q]; fa[q]=nq; fa[np]=nq;
				ans+=len[nq]-len[fa[nq]];
				ans+=len[np]-len[fa[np]];
				ans+=len[q]-len[fa[q]];
				for(;p&&ch[p][c]==q;p=fa[p])ch[p][c]=nq;
				memcpy(ch[nq],ch[q],sizeof(ch[q]));
			}
		}
	}
	void insert(const char*s){for(int i=0;s[i]!='\0';i++)insert(s[i]-'a');}
	void insert(const string&s){for(int i=0;i<(int)s.size();i++)insert(s[i]-'a');}

}sam;
string str;
int n;
void solve()
{
	cin>>str;
	n=str.size();
	for(int i=0;i<n;i++)
	{
		sam.clear();
		for(int j=i;j<n;j++){
			sam.insert(str[j]-'a');
			ans[i][j]=sam.ans;
		}
	}
	int q;cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<ans[x-1][y-1]<<endl;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}