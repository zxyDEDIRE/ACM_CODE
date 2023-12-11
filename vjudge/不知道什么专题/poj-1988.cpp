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
bool vis[maxn];
int dep[maxn];
int son[maxn];
int p[maxn];
int n;
void init(int x){
	if(!vis[x])vis[x]=1,p[x]=x,son[x]=1,dep[x]=0;
}
int find(int r)
{
	if(p[r]==r)return p[r];
	int tmp=p[r];
	p[r]=find(tmp);
	dep[r]+=dep[tmp];
	return p[r];
}
void solve()
{
	cin>>n;
	while(n--)
	{
		char fl;int x,y;
		cin>>fl;
		if(fl=='M')
		{
			cin>>x>>y;
			init(x);
			init(y);
			int fa=find(x);
			int fb=find(y);
			if(fa!=fb)
			{
				p[fb]=fa;
				dep[fb]=son[fa];
				son[fa]+=son[fb];
			}
			
		}
		else if(fl=='C')
		{
			cin>>x;
			init(x);
			cout<<find(x)<<" "<<son[find(x)]<<" "<<dep[x]<<endl;
			cout<<find(x)<<" "<<son[find(x)]<<" "<<dep[x]<<endl;
			cout<<son[find(x)]-dep[x]-1<<endl;
		}
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // int __;cin>>__;
    // while(__--)
        solve();
    return 0;
}