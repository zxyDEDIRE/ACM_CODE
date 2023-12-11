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
class SQAM{
public:
	int ch[maxn][26];
	int nxt[30];
	int tot;
	void init(string&s)
	{
		tot=s.size()+1;
		int _n=s.size();
		for(int i=_n-1;i>=0;i--){
			nxt[s[i]-'a']=i+2;
			for(int j=0;j<26;j++)
				ch[i+1][j]=nxt[j];
		}
	}
	void debug(){
		for(int i=0;i<=tot;i++)
			for(int j=0;j<26;j++)
				if(ch[i][j]){
					// cout<<i<<" --"<<(char)(j+'a')<<"--> "<<ch[i][j]<<endl;
					cout<<i<<" "<<ch[i][j]<<" "<<(char)(j+'a')<<endl;
				}
	}
}sa,sb;
string s,t;
void solve()
{
	cin>>s>>t;
	sa.init(s);
	sb.init(t);
	sa.debug();
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}