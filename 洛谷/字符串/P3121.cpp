/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const ull str_mod=212370440130137957ll;
const ull more=19260817;
const ull prime=233317;
const ull base=131;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+10;
string mp[maxn];
vector<string>v;
int n;
struct Trie{
	int nxt[maxn][26],fail[maxn];
	int val[maxn];
	int cnt[maxn];
	int id[maxn];
	int q[maxn];
	int root=0,indx=0;
	int top=0,low=1;
	void clear(){
		for(int i=0;i<=indx;i++)
		{
			val[i]=cnt[i]=id[i]=q[i]=fail[i]=0;
			for(int j=0;j<26;j++)
				nxt[i][j]=0;
		}
		indx=top=0;
		low=1;
		v.clear();
	}
	void insert(string& str,int x)
	{
		int rt=0;
		for(int i=0;i<str.size();i++)
		{
			int tmp=str[i]-'a';
			if(!nxt[rt][tmp])nxt[rt][tmp]=++indx;
			rt=nxt[rt][tmp];
		}
		val[rt]=str.size();
		id[x]=rt;
	}
	void build()
	{
		for(int i=0;i<26;i++)
			if(nxt[0][i])
				q[++top]=nxt[0][i];
		while(low<=top)
		{
			int x=q[low++];
			for(int i=0;i<26;i++)
			{
				int &rt=nxt[x][i];
				if(!rt)rt=nxt[fail[x]][i];
				else
				{
					fail[rt]=nxt[fail[x]][i];
					q[++top]=rt;
				}
			}
		}
	}
	stack<int>st;
	int vis[maxn];
	void query(string& s)
	{
		st.push(0);
		int rt=0;
		int ans=0;
		for(int i=0;i<s.size();i++)
		{
			int tmp=s[i]-'a';
			rt=nxt[rt][tmp];
			st.push(rt);
			if(val[rt])
			{
				vis[i]=val[rt];
				for(int i=1;i<=val[rt];i++)
					st.pop();
				rt=st.top();
			}
		}
		string str;
		int cnt=0;
		for(int i=s.size()-1;i>=0;i--)
		{
			cnt+=vis[i];
			if(cnt)cnt--;
			else str+=s[i];
		}
		reverse(str.begin(),str.end());
		cout<<str<<endl;
	}
}trie;
void solve()
{
	{
		string t;
		cin>>t>>n;
		for(int i=1;i<=n;i++)
		{
			string str;
			cin>>str;
			mp[i]=str;
			trie.insert(str,i);
		}
		trie.build();
		trie.query(t);
	}
}
signed main(){
  //freopen("C:\\Users\\tob\\Desktop\\P3796_1.in.txt","r",stdin);
  //freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
  //fclose(stdin);
  //fclose(stdout);
	return 0;
}
/*

*/