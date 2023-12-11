/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
vector<int>v[maxn];
bitset<maxn>vis;
int in[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int m;cin>>m;

		if(m==0||m==-1)m++;
		while(m--){
			int x;cin>>x;
			if(x!=-1)
			{
				v[i].push_back(x);
				in[x]++;
			}
			
		}

	}
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i),vis[i]=1;
	while(!q.empty())
	{
		auto x=q.front();q.pop();
		vis[x]=1;
		cout<<x<<" ";
		for(auto y:v[x])
		{
			if(vis[y])continue;
			vis[y]=1;
			q.push(y);
			break;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
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
213
54
*/