#include<bits/stdc++.h>
using namespace std;
// #define endl "\n"
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
const int maxn=2e6+100;
vector<int>v[maxn];
int col[maxn],tot;
bitset<maxn>vis;
int in[maxn];
pii p[maxn];
string str;
int n,m;
vector<int>f(string &str){
	vector<int>v;
	int cnt=0;
	for(auto i:str)
	{
		if(i>='0'&&i<='9')
			cnt=cnt*10+i-'0';
		else if(cnt)v.push_back(cnt),cnt=0;
	}
	if(cnt)v.push_back(cnt);
	return v;
}
void NO(){
	cout<<"conflict"<<endl;
}
void solve(){
	cin>>m>>n;getchar();
	for(int i=1;i<=n;i++)
		col[i]=-1,vis[i]=0;
	queue<int>q;
	for(int i=1;i<=m;i++)
	{
		getline(cin,str);
		auto li=f(str);
		if(str.find("->")==-1)
		{
			if(str[0]=='!')
			{
				int x=li.back();
				if(col[x]!=-1)return NO();
				col[x]=0;
			}
			else if(str[0]!='!')
			{
				int x=li.back();
				if(col[x]!=-1)return NO();
				col[x]=1;
				if(!vis[x])q.push(x),vis[x]=1;
			}
		}
		else if(str.find("->")!=-1)
		{
			int x=li.back();li.pop_back();
			int fl=0;
			if(str.find("!")==-1)fl=1;
			for(auto y:li)
				v[y].push_back(i),in[i]++;
			p[i]={x,fl};
		}
	}
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(auto y:v[x])
		{
			in[y]--;
			if(!in[y])
			{
				auto [to,fl]=p[y];
				if(fl==1){
					if(col[to]==0)return NO();
					col[to]=1;
					if(!vis[to])q.push(to),vis[to]=1;
				}
				else{
					if(col[to]==1)return NO();
					col[to]=0;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(col[i]!=1)cout<<"F";
		else cout<<"T";
	cout<<endl;
}
signed main(){
		solve();
	return 0;
}