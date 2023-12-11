/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
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
int in[maxn];
int n,m;
void NO(){cout<<"NO"<<endl;}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[y].push_back(x);
		in[y]++;
	}
	for(int i=1;i<=n;i++)
		if(in[i]==0)return NO();
	for(int i=1;i<=n;i++)
		if(in[i]==1)
		{
			int y=v[i][0];
			if(in[y]==1&&v[y][0]==i)return NO();
		}
	cout<<"YES"<<endl;
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