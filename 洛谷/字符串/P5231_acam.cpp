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
const int maxn=1e7+100;
class ACAM{
public:
	int ch[maxn][4],nxt[maxn];
	vector<int>v[maxn];
	int len[maxn];
	int fa[maxn];
	int in[maxn];
	bitset<maxn>vis;
	int id[maxn];
	int root=0,indx=0;
	void insert(const string &str,int x){
		int rt=0;
		for(int i=0;i<str.size();i++){
			int tmp=f(str[i]);
			if(!ch[rt][tmp]){
				ch[rt][tmp]=++indx;
				fa[indx]=rt;
			}
			rt=ch[rt][tmp];
		}
		len[x]=str.size();
		id[x]=rt;
	}
	void build()
	{
		queue<int>q;
		for(int i=0;i<4;i++)
			if(ch[0][i])
				q.push(ch[0][i]);
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int i=0;i<4;i++){
				int &rt=ch[x][i];
				if(!rt) rt=ch[nxt[x]][i];
				else{
					nxt[rt]=ch[nxt[x]][i];
					v[nxt[rt]].push_back(rt);
					in[rt]++;
					q.push(rt);
				}
			}
		}
	}
	int f(char ch){
		if(ch=='E')return 0;
		else if(ch=='S')return 1;
		else if(ch=='W')return 2;
		else return 3;
	}
	void query(const string&s,int n)
	{
		int rt=0;
		for(auto i:s)
		{
			rt=ch[rt][f(i)];
			vis[rt]=1;
		}
		queue<int>q;
		for(int i=0;i<=indx;i++)
			if(!in[i])
				q.push(i);
		while(!q.empty())
		{
			int x=q.front();q.pop();
			for(auto y:v[x])
			{
				vis[y]=(vis[y]|vis[x]);
				in[y]--;
				if(!in[y])q.push(y);
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			int rt=id[i];
			int l=len[i];
			while(rt&&!vis[rt])
				rt=fa[rt],l--;
			cout<<l<<endl;
		}

	}
}acam;
string s,t;
int n,m;
void solve()
{
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=m;i++){
		cin>>t;
		acam.insert(t,i);
	}
	acam.build();
	acam.query(s,m);
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}