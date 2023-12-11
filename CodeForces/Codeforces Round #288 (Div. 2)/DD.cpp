/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
// struct Edge{
// 	int to,next,w;
// }edge[maxn];
// int head[maxn],cnt;
map<pair<char,char>,int>mp;
map<int,pair<char,char>>pm;
vector<int>path;
int v[3900][3900];
int out[maxn];
int in[maxn];
string s;
int n,tot;
// void add(int from,int to,int w)
// {
// 	edge[++cnt].w=w;
// 	edge[cnt].to=to;
// 	edge[cnt].next=head[from];
// 	head[from]=cnt;
// }
int f(int i)
{
	if(mp.count({s[i],s[i+1]}))
		return mp[{s[i],s[i+1]}];
	else{
		mp[{s[i],s[i+1]}]=++tot;
		pm[tot]={s[i],s[i+1]};
		return tot;
	}
}
void dfs(int x)
{
	for(int i=1;i<=tot;i++){
		while(v[x][i]){
			v[x][i]--;
			dfs(i);
			path.push_back(i);
		}		
	}
	// for(int i=head[x];i;i=edge[i].next)
	// {
	// 	if(edge[i].w==0){
	// 		edge[i].w=1;
	// 		dfs(edge[i].to);
	// 	}
	// }
	// path.push_back(x);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		int x=f(0),y=f(1);
		// add(x,y,0);
		v[x][y]++;
		in[y]++;
		out[x]++;
	}
	int a=0,b=0,c=0,fl=0,st=-1;
	for(int i=1;i<=tot;i++)
		if(in[i]==out[i])c++;
		else if(in[i]==out[i]+1)a++;
		else if(in[i]==out[i]-1)b++,st=i;
		else fl=1;
	if(fl||a>1||b>1||(a&&!b)||(!a&&b)){
		cout<<"NO"<<endl;
		return ;
	}
	if(st==-1)st=1;
	
	dfs(st);
	path.push_back(st);

	if(path.size()!=n+1){
		cout<<"NO"<<endl;
		return ;
	}
	cout<<"YES"<<endl;
	reverse(path.begin(),path.end());
	cout<<pm[path.front()].first<<pm[path.front()].second;
	for(int i=1;i<path.size();i++){
		cout<<pm[path[i]].second;
	}
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
ba
ab
ca
ac
ba 
Educational Codeforces Round 25
*/