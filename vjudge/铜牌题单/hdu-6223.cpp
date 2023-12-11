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
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=3e6;
struct node{
	char ch;
	int x,y;
	bool operator<(const node &a)const{
		if(a.x==x)return a.ch>ch;
		else return a.x<x;
	}
};
char st[maxn];
string str;
int n;
bitset<maxn>vis;
void solve()
{
	cin>>n>>str;
	char ma=str[0];
	for(int i=0;i<n;i++)
		ma=max(ma,str[i]);
	for(int i=1;i<=n;i++)
		st[i]='0';
	st[1]=ma;
	priority_queue<node>q;
	for(int i=0;i<n;i++)
	{
		if(str[i]==ma)
			q.push(node{ma,1,i});
	}
	int last=1;
	while(!q.empty())
	{
		node now=q.top();q.pop();
		char ch=now.ch;
		int x=now.x;
		int y=now.y;
		if(x!=last)
		{
			vis.reset();
			last=x;
		}
		if(ch<st[x])continue;
		if(vis[y])continue;
		vis[y]=1;
		node m;
		m.y=(y*y+1)%n;
		m.ch=str[m.y];
		m.x=x+1;
		st[x+1]=max(st[x+1],m.ch);
		if(x<=n){
			q.push(m);
		}
	}
	for(int i=1;i<=n;i++)
		cout<<st[i];cout<<endl;
}
signed main(){
  //freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","r",stdin);
  //freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	for(int i=1;i<=__;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
 //fclose(stdin);
 //fclose(stdout);
	return 0;
}
