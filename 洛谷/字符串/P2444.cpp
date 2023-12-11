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
const int maxn=3e6+100;
class ACAM{
public:
	int ch[maxn][3],nxt[maxn];
	int val[maxn],cnt[maxn];
	int id[maxn];
	int in[maxn];
	int root=0,indx=0;
	void clear(){
		for(int i=0;i<=indx;i++){
			val[i]=cnt[i]=id[i]=nxt[i]=0;
			for(int j=0;j<26;j++)
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
					val[rt]|=val[ch[nxt[x]][i]];
					// in[ch[nxt[x]][i]]++;
					// cout<<"fail "<<rt<<" -> "<<ch[nxt[x]][i]<<endl;
					q.push(rt);
				}
			}
		}
	}
	void topsort()
	{
		queue<int>q;
		for(int i=1;i<=indx;i++)
			if(!in[i])q.push(i);
		while(!q.empty()){
			int x=q.front();q.pop();
			int y=nxt[x];
			cnt[y]+=cnt[x];
			in[y]--;
			if(!in[y])q.push(y);
		}
	}
	int query()
	{
		for(int i=0;i<=indx;i++)
			for(int j=0;j<=1;j++){
				if(val[i])continue;
				int y=ch[i][j];
				if(val[y])continue;
				in[y]++;
				// cout<<i<<" "<<j<<" "<<y<<endl;
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
		// for(int i=0;i<=indx;i++)
		// 	cout<<in[i]<<" ";cout<<endl;
		for(int i=0;i<=indx;i++)
			if(in[i])return 1;
		return 0;
	}
}acam;
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		acam.insert(str,i);
	}
	acam.build();
	int ans = acam.query();
	if(ans==0)cout<<"NIE"<<endl;
	else cout<<"TAK"<<endl;
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
3
011 
11
00000
*/