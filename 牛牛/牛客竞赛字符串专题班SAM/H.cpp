#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e6+1;
class SAM{
public:
	int ch[maxn][26],siz[maxn],len[maxn],fa[maxn];
	int tot=1,np=1;
	ll ans;
	void insert(const int&c){
		int p=np; np=++tot;
		len[np]=len[p]+1; siz[np]=1;
		for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
		if(p==0)fa[np]=1,ans+=len[np]-len[fa[np]];
		else{
			int q=ch[p][c];
			if(len[q]==len[p]+1)fa[np]=q,ans+=len[np]-len[fa[np]];
			else{
				int nq=++tot;
				len[nq]=len[p]+1;
				ans-=len[q]-len[fa[q]];
				fa[nq]=fa[q];fa[q]=nq;fa[np]=nq;
				ans+=len[np]-len[fa[np]];
				ans+=len[nq]-len[fa[nq]];
				ans+=len[q]-len[fa[q]];
				for(;p&&ch[p][c]==q;p=fa[p])ch[p][c]=nq;
				memcpy(ch[nq],ch[q],sizeof(ch[q]));
			}
		}
	}
	void insert(const string&s){for(int i=0;i<(int)s.size();i++)insert(s[i]-'a');}
}sam;
string str;
void solve()
{
	cin>>str;
	sam.insert(str);
	cout<<sam.ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}