/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
	node(int a,int b):id(a),dis(b){};
};
bitset<maxn>v;
int dis[maxn];
int prime[maxn];
bool vis[maxn];
void init()
{
	for(int i=2;i<=1e5;i++)
	{
		if(!vis[i])prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&prime[j]*i<=maxn;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		} 
	}
}
int stoll_1(string str)
{
	int ans=0;
	for(int i=0;i<str.size();i++)
		ans=ans*10+(str[i]-'0');
	return ans;
}
string to_string_1(int x)
{
	string ans;
	while(x){
		ans=ans+(char)(x%10+'0');
		x/=10;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
void bfs(int s,int t)
{
	for(int i=1;i<=1e5;i++)
		dis[i]=INF;
	priority_queue<node>q;	
	q.push(node(s,0));
	v.reset();
	dis[s]=0;
	while(!q.empty())
	{
		node NOW=q.top();q.pop();
		int x=NOW.id;
		int DIS=NOW.dis;
		if(x==t){
			cout<<DIS<<endl;
			return ;
		}
		if(v[x])continue;
		v[x]=1;
		string str=to_string_1(x);
		for(int i=0;i<4;i++)
		{
			for(char j='0';j<='9';j++)
			{
				if(j==str[i]||(i==0&&j=='0'))continue;
				string now=str;
				now[i]=j;
				int y=stoll_1(now);
				if(vis[y])continue;
				if(dis[y]>dis[x]+1){
					dis[y]=dis[x]+1;
					q.push(node(y,dis[y]));
				}
			}
		}
	}
	cout<<"Impossible"<<endl;
}
void solve()
{
	int a,b;
	cin>>a>>b;
	bfs(a,b);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    init();
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}