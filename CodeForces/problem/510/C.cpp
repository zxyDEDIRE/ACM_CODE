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
vector<int>v[maxn];
string p[maxn];
int vis[maxn];
int in[maxn];
int n;
int f(char ch){return ch-'a'+1;}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	string t=p[1];
	for(int i=2;i<=n;i++)
	{
		int flag=0;
		for(int j=0;j<min(t.size(),p[i].size());j++)
		{
			if(t[j]==p[i][j])continue;
			v[f(t[j])].push_back(f(p[i][j]));
			in[f(p[i][j])]++;
			// cout<<t[j]<<" "<<p[i][j]<<endl;
			flag=1;
			break;
		}
		if(!flag&&t.size()>p[i].size()){
			cout<<"Impossible"<<endl;
			return ;
		}
		t=p[i];
	}
	queue<int>q;
	vector<int>ans;
	for(int i=1;i<=26;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(vis[x])continue;
		ans.push_back(x);
		vis[x]=1;
		for(auto y:v[x])
		{
			in[y]--;
			if(!in[y])
				q.push(y);
		}
	}
	for(int i=1;i<=26;i++)
		if(in[i]){
			cout<<"Impossible"<<endl;
			return ;
		}
	for(auto i:ans)
		cout<<(char)('a'+i-1);
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