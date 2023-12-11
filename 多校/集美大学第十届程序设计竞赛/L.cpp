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
class DSU{
public:
	vector<int>f,num;
	DSU(){}
	void init(int n){
		f.resize(n+1);
		num.resize(n+2);
		iota(f.begin(),f.end(),0);
		for(int i=1;i<=n;i++)
			num[i]=1;
	}
	int find(int r){
		return f[r]=f[r]==r?f[r]:find(f[r]);
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	void merge(int x,int y){
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)
			f[fa]=fb,num[fb]+=num[fa];
	}
}dsu;
struct node{
	vector<string>p;
	// set<string>p;
	string name;
}p[maxn];
map<string,int>mp,na;
vector<int>v[maxn];
int n,m,indx;
string f(string &str)
{
	string now;
	for(auto i:str)
	{
		if(i>='A'&&i<='Z')now.push_back(i-'A'+'a');
		else now.push_back(i);
	}
	return now;
}
void solve()
{
	cin>>n>>m;
	dsu.init(n+1);
	for(int i=1;i<=n;i++)
	{
		string str,now;
		cin>>str>>p[i].name;
		str=f(str);
		for(auto ch:str)
		{
			if(ch=='_')
				p[i].p.push_back(now),now="";
			else now.push_back(ch);
		}
		if(now!="")
			p[i].p.push_back(now);
		// cout<<"I:"<<i<<endl;
		// for(auto I:p[i].p)
		// 	cout<<I<<" ";cout<<endl;
		if(mp.count(p[i].name))
		{
			int x=mp[p[i].name];
			dsu.merge(x,i);
		}
		mp[p[i].name]=i;


		for(auto s:p[i].p)
		{
			if(!na.count(s))
				na[s]=++indx;
			v[na[s]].push_back(i);
		}
	}
	for(int i=1;i<=m;i++)
	{
		string str;cin>>str;
		str=f(str);
		if(!na.count(str))continue;
		int pre=0;
		for(auto j:v[na[str]])
		{
			if(pre!=0)dsu.merge(pre,j);
			pre=j;
		}
	}
	for(int i=1;i<=n;i++)
		cout<<dsu.num[dsu.find(i)]-1<<endl;
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
4 1
jimei_University Xiamen
xiamen_University iamen
genshin_University Mihoyo
genshin_Impact ihoyo
genshin
*/