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
class ACAM{
public:
	int ch[maxn][26],nxt[maxn];
	int val[maxn],cnt[maxn];
	int id[maxn];
	int in[maxn];
	int root=0,indx=0;
	void clear(){
		for(int i=0;i<=indx;i++){
			val[i]=cnt[i]=id[i]=nxt[i]=0;
			for(int j=0;j<2;j++)
				ch[i][j]=0;
		}
		indx=0;
	}
	void insert(const string &str,int x){
		int rt=0;
		for(int i=0;i<str.size();i++){
			int tmp=str[i]-'0';
			if(!ch[rt][tmp]){
				ch[rt][tmp]=++indx;
				// cout<<"ins  "<<rt<<" --"<<str[i]<<"--> "<<indx<<endl;
			}
			rt=ch[rt][tmp];
		}
		val[rt]++;
		id[x]=rt;
	}
	void build()
	{
		queue<int>q;
		for(int i=0;i<2;i++)
			if(ch[0][i])
				q.push(ch[0][i]);
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int i=0;i<2;i++){
				int &rt=ch[x][i];
				if(!rt) rt=ch[nxt[x]][i];
				else{
					nxt[rt]=ch[nxt[x]][i];
					val[rt]|=val[nxt[rt]];
					// cout<<"fail "<<rt<<" -> "<<ch[nxt[x]][i]<<endl;
					q.push(rt);
				}
			}
		}
	}
	void query()
	{
		for(int i=0;i<=indx;i++)
			for(int j=0;j<=1;j++){
				if(val[i]||val[ch[i][j]])continue;
				in[ch[i][j]]++;
			}
		queue<int>q;
		for(int i=0;i<=indx;i++)
			if(!in[i]&&!val[i])
				q.push(i);
		while(!q.empty())
		{
			int x=q.front();q.pop();
			for(int i=0;i<=1;i++)
			{
				int y=ch[x][i];
				if(val[y])continue;
				in[y]--;
				if(!in[y]&&!val[y])q.push(y);
			}
		}
		for(int i=0;i<=indx;i++)
			if(in[i]){
				cout<<"TAK"<<endl;
				return ;
			}
		cout<<"NIE"<<endl;
	}
}acam;
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		acam.insert(s,i);
	}
	acam.build();
	acam.query();
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}